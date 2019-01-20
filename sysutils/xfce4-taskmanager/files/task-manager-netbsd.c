/*
 * Copyright (c) 2008-2014 Landry Breuil <landry@xfce.org>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Library General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 */

#include <stdlib.h>
#include <err.h>
#include <sys/types.h>
/* for sysctl() */
#include <sys/param.h>
#include <sys/sched.h>
#include <sys/sysctl.h>
/* for swapctl() */
#include <sys/swap.h>
/* for strlcpy() */
#include <string.h>
/* for getpagesize() */
#include <unistd.h>
/* for P_ZOMBIE & SSLEEP */
#include <sys/proc.h>
/* for struct vmtotal */
#include <sys/vmmeter.h>
#include "task-manager.h"

#define _KMEMUSER
#include <kvm.h>

#include <errno.h>

char	*state_abbrev[] = {
	"", "start", "run", "sleep", "stop", "zomb", "dead", "onproc"
};

gboolean get_task_list (GArray *task_list)
{
	Task t;
	struct kinfo_proc2 *kp, p;
	char **args;
	gchar* buf;
	int i, nproc = 0;

        char errbuf[_POSIX2_LINE_MAX];
        kvm_t *kdp = kvm_open(NULL, NULL, NULL, KVM_NO_FILES, errbuf);
        if (kdp == NULL)
                errx(1, "%s", errbuf);

        if (!(kp = kvm_getproc2(kdp, KERN_PROC_ALL, 0,
                    sizeof(struct kinfo_proc2), &nproc)))
                err(1, "%s", kvm_geterr(kdp));

        for (i = 0; i < nproc; i++) {
		if (kp[i].p_pid < 1)
			continue; /* not valid */
		
		p = kp[i];
		t.pid = p.p_pid;
		t.ppid = p.p_ppid;
		t.uid = p.p_uid;
		t.prio = p.p_priority - PZERO;
		t.vsz = p.p_vm_dsize + p.p_vm_ssize + p.p_vm_tsize;
		t.vsz *= getpagesize();
		t.rss = p.p_vm_rssize * getpagesize();
		g_snprintf(t.state, sizeof(t.state), "%s", state_abbrev[p.p_stat]);
		g_strlcpy(t.name, p.p_comm, strlen(p.p_comm) + 1);

		if (!(p.p_stat == SDEAD)) {
			args = kvm_getargv2(kdp, &kp[i], BUFSIZ);
			if (args != NULL) {
				buf = g_strjoinv(" ", args);
				g_strlcpy(t.cmdline, buf, sizeof(t.cmdline));
			}
			t.cpu_user = (100.0f * ((gfloat) p.p_pctcpu / FSCALE));
			t.cpu_system = 0.0f; /* XXX TODO */
			g_array_append_val(task_list, t);
		}
	}
	
	g_free(args);
	g_free(buf);
	g_free(kp);

	g_array_sort (task_list, task_pid_compare_fn);

	return TRUE;
}

gboolean
pid_is_sleeping (GPid pid)
{
	int mib[6];
	struct kinfo_proc2 kp;
	size_t size = sizeof(struct kinfo_proc2);

	mib[0] = CTL_KERN;
	mib[1] = KERN_PROC2;
	mib[2] = KERN_PROC_PID;
	mib[3] = pid;
	mib[4] = size;
	mib[5] = 1;
	if (sysctl(mib, 6, &kp, &size, NULL, 0) < 0)
		errx(1, "could not read kern.proc2 for pid %d", pid);
	return (kp.p_stat == SSTOP ? TRUE : FALSE);
}

gboolean get_cpu_usage (gushort *cpu_count, gfloat *cpu_user, gfloat *cpu_system)
{
	size_t len = sizeof(*cpu_count);
	sysctlbyname("hw.ncpu", cpu_count, &len, NULL, 0);

	static gulong cp_user_old = 0, cp_system_old = 0, cp_total_old = 0;
	static gulong cp_user = 0, cp_system = 0, cp_total = 0;

 	glong cpu_state[CPUSTATES] = { 0 };
 	len = sizeof(cpu_state);
	sysctlbyname("kern.cp_time", &cpu_state, &len, NULL, 0);

	cp_user_old = cp_user;
	cp_system_old = cp_system;
	cp_total_old = cp_total;
	cp_user = cpu_state[CP_USER] + cpu_state[CP_NICE];
	cp_system = cpu_state[CP_SYS] + cpu_state[CP_INTR];
	cp_total = cpu_state[CP_IDLE] + cp_user + cp_system;

	*cpu_user = *cpu_system = 0.0f;
	if (cp_total > cp_total_old)
	{
		*cpu_user = (((cp_user - cp_user_old) * 100.0f) / (float)(cp_total - cp_total_old));
		*cpu_system = (((cp_system - cp_system_old) * 100.0f) / (float)(cp_total - cp_total_old));
	}

	return TRUE;
}

/* vmtotal values in #pg */
#define pagetok(nb) ((nb) * (getpagesize()))

gboolean get_memory_usage (guint64 *memory_total, guint64 *memory_free,
		guint64 *memory_cache, guint64 *memory_buffers,
		guint64 *swap_total, guint64 *swap_free)
{
	int mib[] = {CTL_VM, VM_METER};
	struct vmtotal vmtotal;
	struct swapent *swdev;
	int nswap, i;
	size_t size;

	size = sizeof(vmtotal);
	if (sysctl(mib, 2, &vmtotal, &size, NULL, 0) < 0)
		errx(1,"failed to get vm.meter");

	mib[0] = CTL_HW;
	mib[1] = HW_PHYSMEM64;
	uint64_t physmem;
	size_t physmemlen = sizeof(physmem);

	if (sysctl(mib, 2, &physmem, &physmemlen, NULL, 0) < 0)
		errx(1, "failed to get physmem");

	*memory_total = (guint64)physmem;
	*memory_free = pagetok((guint64)vmtotal.t_free);
	*memory_cache = 0;
	*memory_buffers = pagetok(vmtotal.t_rm - vmtotal.t_arm);

	/* get swap stats */
	if ((nswap = swapctl(SWAP_NSWAP, 0, 0)) == 0)
		errx(1,"failed to get swap device count");

	if ((swdev = calloc(nswap, sizeof(*swdev))) == NULL)
		errx(1,"failed to allocate memory for swdev structures");

	if (swapctl(SWAP_STATS, swdev, nswap) == -1) {
		free(swdev);
		errx(1,"failed to get swap stats");
	}

	/* Total things up */
	*swap_total = *swap_free = 0;
	for (i = 0; i < nswap; i++) {
		if (swdev[i].se_flags & SWF_ENABLE) {
			*swap_free += (swdev[i].se_nblks - swdev[i].se_inuse);
			*swap_total += swdev[i].se_nblks;
		}
	}
	*swap_total *= DEV_BSIZE;
	*swap_free *= DEV_BSIZE;
	free(swdev);

	return TRUE;
}

