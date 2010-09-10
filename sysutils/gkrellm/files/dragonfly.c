/* GKrellM
|  Copyright (C) 1999-2005 Bill Wilson
|
|  Author:  Bill Wilson    bill@gkrellm.net
|  Latest versions might be found at:  http://gkrellm.net
|
|  DragonFly code: Joerg Sonnenberger <joerg@bec.de>
|  Derived from FreeBSD code: Hajimu UMEMOTO <ume@FreeBSD.org>
|
|  This program is free software which I release under the GNU General Public
|  License. You may redistribute and/or modify this program under the terms
|  of that license as published by the Free Software Foundation; either
|  version 2 of the License, or (at your option) any later version.
|
|  This program is distributed in the hope that it will be useful,
|  but WITHOUT ANY WARRANTY; without even the implied warranty of
|  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
|  GNU General Public License for more details.  Version 2 is in the
|  COPYRIGHT file in the top level directory of this distribution.
| 
|  To get a copy of the GNU General Puplic License, write to the Free Software
|  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/

#include <kvm.h>

kvm_t	*kvmd = NULL;
char	errbuf[_POSIX2_LINE_MAX];


// extern gboolean force_meminfo_update(void);
#if defined(__i386__)
static void scan_for_sensors();
#endif


void
gkrellm_sys_main_init(void)
	{
	/* We just ignore error, here.  Even if GKrellM doesn't have
	|  kmem privilege, it runs with available information.
	*/
	kvmd = kvm_openfiles(NULL, NULL, NULL, O_RDONLY, errbuf);
	if (setgid(getgid()) != 0)
		{
		fprintf(stderr, "Can't drop setgid privileges.");
		exit(1);
		}
#if defined(__i386__)
	scan_for_sensors();
#endif
	if (setuid(getuid()) != 0)
		{
		fprintf(stderr, "Can't drop setuid privileges.");
		exit(1);
		}
	}

void
gkrellm_sys_main_cleanup(void)
	{
	}

#include <sys/param.h>
#include <sys/sysctl.h>

static int
gk_sysctlnametomib(const char *name, int *mibp, size_t *lenp)
	{
	static int	oid_name2oid[2] = { 0, 3 };

	if (sysctl(oid_name2oid, 2, mibp, lenp,
		   (void *)name, strlen(name)) < 0)
		return -1;
	*lenp /= sizeof(int);
	return 0;
	}

/* ===================================================================== */
/* CPU monitor interface */

#include <kinfo.h>
#include <kvm.h>


extern	kvm_t	*kvmd;

void
gkrellm_sys_cpu_read_data(void)
{
	struct kinfo_cputime cp_time;

	if (kinfo_get_sched_cputime(&cp_time))
		return;

	gkrellm_cpu_assign_data(0, cp_time.cp_user, cp_time.cp_nice,
				cp_time.cp_sys, cp_time.cp_idle);
}

gboolean
gkrellm_sys_cpu_init(void)
{
	gkrellm_cpu_set_number_of_cpus(1);
	return TRUE;
}


/* ===================================================================== */
/* Proc monitor interface */

#include <osreldate.h>
#include <sys/sysctl.h>
#include <sys/user.h>

/*
 * This is ugly, but we need PID_MAX, in anyway.  Since 5.0-RELEASE
 * will have vm.stats.vm.v_forks, this will be obsolete in the future.
 */
#define	PID_MAX		99999

#include <kvm.h>
#include <limits.h>
#include <paths.h>
#include <utmp.h>

extern	kvm_t	*kvmd;

static int	oid_v_forks[CTL_MAXNAME + 2];
static int	oid_v_vforks[CTL_MAXNAME + 2];
static int	oid_v_rforks[CTL_MAXNAME + 2];
static size_t	oid_v_forks_len = sizeof(oid_v_forks);
static size_t	oid_v_vforks_len = sizeof(oid_v_vforks);
static size_t	oid_v_rforks_len = sizeof(oid_v_rforks);

gboolean
gkrellm_sys_proc_init(void)
	{
	static const char	*name = "vm.stats.vm.v_forks";
	static const char	*vname = "vm.stats.vm.v_vforks";
	static const char	*rname = "vm.stats.vm.v_rforks";

	/* check if vm.stats.vm.v_forks is available */
	if (gk_sysctlnametomib(name, oid_v_forks, &oid_v_forks_len) < 0)
		return FALSE;
	if (gk_sysctlnametomib(vname, oid_v_vforks, &oid_v_vforks_len) < 0)
		return FALSE;
	if (gk_sysctlnametomib(rname, oid_v_rforks, &oid_v_rforks_len) < 0)
		return FALSE;
	return TRUE;
	}

void
gkrellm_sys_proc_read_data(void)
	{
	static int	oid_proc[] = { CTL_KERN, KERN_PROC, KERN_PROC_ALL };
	double		avenrun;
	u_int		n_forks, n_vforks, n_rforks, n_processes;
	int		r_forks, r_vforks, r_rforks;
	size_t		len;

	if (getloadavg(&avenrun, 1) <= 0)
		avenrun = 0;

	/* We don't want to just use sysctlbyname().  Because,
             * we call it so often. */
	len = sizeof(n_forks);
	r_forks = sysctl(oid_v_forks, oid_v_forks_len,
			 &n_forks, &len, NULL, 0);
	len = sizeof(n_vforks);
	r_vforks = sysctl(oid_v_vforks, oid_v_vforks_len,
			  &n_vforks, &len, NULL, 0);
	len = sizeof(n_rforks);
	r_rforks = sysctl(oid_v_rforks, oid_v_rforks_len,
			  &n_rforks, &len, NULL, 0);
	if (r_forks >= 0 && r_vforks >= 0 && r_rforks >= 0)
		n_forks = n_forks + n_vforks + n_rforks;
	else
		n_forks = 0;

	if (sysctl(oid_proc, 3, NULL, &len, NULL, 0) >= 0)
		n_processes = len / sizeof(struct kinfo_proc);
	else
		n_processes = 0;
	gkrellm_proc_assign_data(n_processes, 0, n_forks, avenrun);
	}

void
gkrellm_sys_proc_read_users(void)
	{
	gint		n_users;
	struct stat	sb, s;
	gchar		ttybuf[MAXPATHLEN];
	FILE		*ut;
	struct utmp	utmp;
	static time_t	utmp_mtime;

	if (stat(_PATH_UTMP, &s) != 0 || s.st_mtime == utmp_mtime)
		return;
	if ((ut = fopen(_PATH_UTMP, "r")) != NULL)
		{
		n_users = 0;
		while (fread(&utmp, sizeof(utmp), 1, ut))
			{
			if (utmp.ut_name[0] == '\0')
				continue;
			(void)snprintf(ttybuf, sizeof(ttybuf), "%s/%s",
				       _PATH_DEV, utmp.ut_line);
			/* corrupted record */
			if (stat(ttybuf, &sb))
				continue;
			++n_users;
			}
		(void)fclose(ut);
		gkrellm_proc_assign_users(n_users);
		}
	utmp_mtime = s.st_mtime;
	}


/* ===================================================================== */
/* Disk monitor interface */

#include <devstat.h>
static struct statinfo	statinfo_cur;

gchar *
gkrellm_sys_disk_name_from_device(gint device_number, gint unit_number,
			gint *order)
	{
	return NULL;	/* Not implemented */
	}

gint
gkrellm_sys_disk_order_from_name(gchar *name)
	{
	return -1;	/* Append as added */
	}

void
gkrellm_sys_disk_read_data(void)
	{
	int			ndevs;
	int			num_selected;
	int			num_selections;
	int			maxshowdevs = 10;
	struct device_selection	*dev_select = NULL;
	long			select_generation;
	int			dn;
	gchar		name[32];

	if (getdevs(&statinfo_cur) < 0)
		return;
	ndevs = statinfo_cur.dinfo->numdevs;
	if (selectdevs(&dev_select, &num_selected, &num_selections,
		       &select_generation, statinfo_cur.dinfo->generation,
		       statinfo_cur.dinfo->devices, ndevs,
		       NULL, 0, NULL, 0,
		       DS_SELECT_ONLY, maxshowdevs, 1) >= 0)
		{
		for (dn = 0; dn < ndevs; ++dn)
			{
			int		di;
			struct devstat	*dev;
//			int		block_size;
//			int		blocks_read, blocks_written;

			di = dev_select[dn].position;
			dev = &statinfo_cur.dinfo->devices[di];
//			block_size = (dev->block_size > 0)
//				   ? dev->block_size : 512;
//			blocks_read = dev->bytes_read / block_size;
//			blocks_written = dev->bytes_written / block_size;

			/* to use gkrellm_disk_assign_data_by_device() would need
			   gkrellm_sys_disk_name_from_device() implemented */
			snprintf(name, sizeof(name), "%s%d", dev->device_name,
					dev->unit_number);
			gkrellm_disk_assign_data_by_name(name,
					dev->bytes_read, dev->bytes_written, FALSE);
			}
		free(dev_select);
		}
	}

gboolean
gkrellm_sys_disk_init(void)
	{
	bzero(&statinfo_cur, sizeof(statinfo_cur));
	statinfo_cur.dinfo = (struct devinfo *)malloc(sizeof(struct devinfo));
	bzero(statinfo_cur.dinfo, sizeof(struct devinfo));
	return TRUE;
	}


/* ===================================================================== */
/* Inet monitor interface */

#include "../inet.h"

#include <netinet6/ip6_var.h>
#include <netinet/in_pcb.h>
#include <netinet/ip_var.h>
#include <netinet/ip6.h>
#include <netinet/tcp.h>
#include <netinet/tcpip.h>
#include <netinet/tcp_seq.h>
#include <netinet/tcp_fsm.h>
#include <netinet/tcp_timer.h>
#include <netinet/tcp_var.h>


void
gkrellm_sys_inet_read_tcp_data(void)
	{
	void *so_begin, *so_end;
	struct xtcpcb *xtp;
	struct inpcb *inp;
	struct xsocket *so;
	const char *varname, *protoname;
	size_t len;
	void *buf;
	int vflag;
	ActiveTCP	tcp;
	gint		tcp_status;

	varname = "net.inet.tcp.pcblist";
	protoname = "tcp";

	vflag = INP_IPV4 | INP_IPV6;

	buf = NULL;
	len = 0;

	if (sysctlbyname(varname, NULL, &len, NULL, 0)) {
		goto out;
	}
	if ((buf = malloc(len)) == NULL)
		goto out;
	if (sysctlbyname(varname, buf, &len, NULL, 0)) {
		goto out;

	so_begin = buf;
	so_end = (uint8_t *)buf + len;

	for (so_begin = buf, so_end = (uint8_t *)so_begin + len;
	     (uint8_t *)so_begin + sizeof(size_t) < (uint8_t *)so_end &&
	     (uint8_t *)so_begin + *(size_t *)so_begin <= (uint8_t *)so_end;
	     so_begin = (uint8_t *)so_begin + *(size_t *)so_begin) {
		xtp = (struct xtcpcb *)so_begin;
		if (xtp->xt_len != sizeof *xtp)
			goto out;
		inp = &xtp->xt_inp;
		so = &xtp->xt_socket;
		if ((inp->inp_vflag & vflag) == 0)
			continue;
		if (inp->inp_vflag & INP_IPV4) {
			tcp.remote_addr.s_addr = inp->inp_faddr.s_addr;
			tcp.family = AF_INET;
		} else if (inp->inp_vflag & INP_IPV6) {
			memcpy(&tcp.remote_addr6,
			       &inp->in6p_faddr,
			       sizeof(struct in6_addr));
				tcp.family = AF_INET6;
		}

		tcp.remote_port = ntohs(inp->inp_fport);
		tcp.local_port = ntohs(inp->inp_lport);
		tcp_status = (xtp->xt_tp.t_state == TCPS_ESTABLISHED);
		if (tcp_status == TCP_ALIVE)
			gkrellm_inet_log_tcp_port_data(&tcp);
		}
	}
out:
	free(buf);
	}


gboolean
gkrellm_sys_inet_init(void)
	{
	return TRUE;
	}


/* ===================================================================== */
/* Memory/Swap monitor interface */

#include <osreldate.h>
#include <kvm.h>
#include <limits.h>
#include <sys/conf.h>
#include <sys/vmmeter.h>
#include <sys/sysctl.h>
#include <vm/vm_param.h>

extern	char	errbuf[];

static int
swapmode(guint64 *retavail, guint64 *retfree)
	{
	guint64 used, avail;
	static int psize = -1;
	struct kvm_swap kvmswap;

	/*
	 * Counter for error messages. If we reach the limit,
	 * stop reading information from swap devices and
	 * return zero. This prevent endless 'bad address'
	 * messages.
	 */
	static int warning = 10;

	if (warning <= 0)
		{
		/* a single warning */
		if (!warning)
	    		{
			warning--;
			fprintf(stderr, "Too much errors, stop reading swap devices ...\n");
			}
		return(0);
		}
	warning--;		/* decrease counter, see end of function */

	if (kvmd == NULL)
		return(0);
	if (kvm_getswapinfo(kvmd, &kvmswap, 1, 0) < 0)
		{
		fprintf(stderr, "kvm_getswapinfo failed\n");
		return(0);
		}

	if (psize < 0)
	    psize = getpagesize();
	*retavail = avail = (quad_t)kvmswap.ksw_total * psize;
	used = (quad_t)kvmswap.ksw_used * psize;
	*retfree = avail - used;

	/* increase counter, no errors occurs */
	warning++; 

	return  (int)(((double)used / (double)avail * 100.0) + 0.5);
	}

static int
get_bufspace(guint64 *bufspacep)
	{
	static const char	*name = "vfs.bufspace";
	static int	oid_bufspace[CTL_MAXNAME + 2];
	static size_t	oid_bufspace_len = sizeof(oid_bufspace);
	static gint	initialized = 0;
	u_int		bufspace;
	size_t		bufspace_len = sizeof(bufspace);

	if (!initialized)
		{
		if (gk_sysctlnametomib(name, oid_bufspace,
				       &oid_bufspace_len) < 0)
			return 0;
		++initialized;
		}

	if (sysctl(oid_bufspace, oid_bufspace_len,
		   &bufspace, &bufspace_len, 0, 0) < 0)
		return 0;
	*bufspacep = bufspace;
	return 1;	
	}

struct mibtab {
    char	*name;
    int		oid[CTL_MAXNAME + 2];
    size_t	oid_len;
    u_int	value;
    size_t	value_len;
};

static struct mibtab mibs[] = {
#define MIB_V_PAGE_COUNT	0
    { "vm.stats.vm.v_page_count" },
#define MIB_V_FREE_COUNT	1
    { "vm.stats.vm.v_free_count" },
#define MIB_V_WIRE_COUNT	2
    { "vm.stats.vm.v_wire_count" },
#define MIB_V_ACTIVE_COUNT	3
    { "vm.stats.vm.v_active_count" },
#define MIB_V_INACTIVE_COUNT	4
    { "vm.stats.vm.v_inactive_count" },
#define MIB_V_CACHE_COUNT	5
    { "vm.stats.vm.v_cache_count" },
#define MIB_V_SWAPPGSIN		6
    { "vm.stats.vm.v_swappgsin" },
#define MIB_V_SWAPPGSOUT	7
    { "vm.stats.vm.v_swappgsout" },
    { NULL }
};

#define	PROC_MEMINFO_FILE	"/compat/linux/proc/meminfo"

#ifndef VM_TOTAL
#define VM_TOTAL	VM_METER
#endif

static guint64	swapin,
		swapout,
		swap_total,
		swap_used;

void
gkrellm_sys_mem_read_data(void)
	{
	static gint	psize, pshift = 0;
	static gint	first_time_done = 0;
	guint64		total, used, x_used, free, shared, buffers, cached;
	struct vmtotal	vmt;
	size_t		length_vmt = sizeof(vmt);
	static int	oid_vmt[] = { CTL_VM, VM_TOTAL };
	gint		i;
	FILE		*f;
	gchar		buf[160];

#if 0
	/* mem.c does a force_meminfo_update() before calling this */
	/* Collecting meminfo data is expensive under FreeBSD, so
	|  take extra precautions to minimize reading it.
	*/
	if (!GK.ten_second_tick && !force_meminfo_update())
		return;
#endif

	if (pshift == 0)
		{
		for (psize = getpagesize(); psize > 1; psize >>= 1)
			pshift++;
		}

	shared = 0;

	if (!first_time_done)
		{
		for (i = 0; mibs[i].name; ++i)
			{
			mibs[i].oid_len = sizeof(mibs[i].oid);
			if (gk_sysctlnametomib(mibs[i].name,
					       mibs[i].oid,
					       &mibs[i].oid_len) < 0)
			 	return;
			mibs[i].value_len = sizeof(mibs[i].value);
			}
		++first_time_done;
		}
	for (i = 0; mibs[i].name; ++i)
		if (sysctl(mibs[i].oid, mibs[i].oid_len,
			   &mibs[i].value,
			   &mibs[i].value_len, 0, 0) < 0)
			return;
	total = (mibs[MIB_V_PAGE_COUNT].value -
		     mibs[MIB_V_WIRE_COUNT].value) << pshift;
	x_used = (mibs[MIB_V_ACTIVE_COUNT].value +
		      mibs[MIB_V_INACTIVE_COUNT].value) << pshift;
	free = mibs[MIB_V_FREE_COUNT].value << pshift;
	if (sysctl(oid_vmt, 2, &vmt, &length_vmt, NULL, 0) == 0)
		shared = vmt.t_rmshr << pshift;
	get_bufspace(&buffers);
	cached = mibs[MIB_V_CACHE_COUNT].value << pshift;
	used = x_used - buffers - cached;
	gkrellm_mem_assign_data(total, used, free, shared, buffers, cached);

	swapin = mibs[MIB_V_SWAPPGSIN].value;
	swapout = mibs[MIB_V_SWAPPGSOUT].value;

	if (kvmd == NULL) {
		/* Try linprocfs for swap info */
		if ((f = fopen(PROC_MEMINFO_FILE, "r")) == NULL)
			return;
		/* total: used: free: shared: buffers: cached: */
		while ((fgets(buf, sizeof(buf), f)) != NULL)
			{
			if (strncmp(buf, "Swap:", 5) == 0)
				{
				sscanf(buf, "Swap: %llu %llu",
				       &swap_total, &swap_used);
				break;
				}
			}
		fclose(f);
		return;
	}

	if (first_time_done == 0)
	{
	swapmode(&swap_total, &swap_used);
	swap_used = swap_total - swap_used;
	first_time_done = 1;
	}
	}

void
gkrellm_sys_swap_read_data(void)
	{
	gkrellm_swap_assign_data(swap_total, swap_used, swapin, swapout);
	}

gboolean
gkrellm_sys_mem_init(void)
	{
	return TRUE;
	}


/* ===================================================================== */
/* Battery monitor interface */

#if defined(__i386__)
#include <osreldate.h>
#include <machine/apm_bios.h>
#define	APMDEV		"/dev/apm"

#define	L_NO_BATTERY	0x80
#define	L_ON_LINE		1
#define	L_CHARGING		3
#define L_UNKNOWN		0xFF

/* following two definitions are taken from sys/dev/acpica/acpiio.h */
#define ACPI_BATT_STAT_CHARGING		0x0002
#define ACPI_BATT_STAT_NOT_PRESENT	0x0007

#define ACPI_ACLINE	0
#define ACPI_BATT_LIFE	1
#define ACPI_BATT_TIME	2
#define ACPI_BATT_STATE	3

void
gkrellm_sys_battery_read_data(void)
	{
	static const char	*name[] = { "hw.acpi.acline",
				    "hw.acpi.battery.life",
				    "hw.acpi.battery.time",
				    "hw.acpi.battery.state",
				    NULL };
	static int	oid[CTL_MAXNAME + 2][4];
	static size_t	oid_len[4] = { sizeof(oid[0]), sizeof(oid[1]),
				       sizeof(oid[2]), sizeof(oid[3]) };
	static gboolean	first_time_done = FALSE;
	static gboolean	acpi_enabled = FALSE;
	size_t		size;
	int		acpi_info[4];
	int		i;
	int		f, r;
	struct apm_info	info;
	gboolean	available, on_line, charging;
	gint		percent, time_left;
	gint		batt_num = 0;

	if (!first_time_done)
		{
		first_time_done = TRUE;
#ifdef ACPI_SUPPORTS_MULTIPLE_BATTERIES
		/*
		 * XXX: Disable getting battery information via ACPI
		 * to support multiple batteries via APM sim until
		 * ACPI sysctls support multiple batteries.
		 */
		for (i = 0; name[i] != NULL; ++i)
			{
			if (gk_sysctlnametomib(name[i], oid[i],
					       &oid_len[i]) < 0)
				break;
			}
		if (name[i] == NULL)
			acpi_enabled = TRUE;
#endif
		}

	if (acpi_enabled)
		{
			for (i = 0; name[i] != NULL; ++i)
				{
				size = sizeof(acpi_info[i]);
				if (sysctl(oid[i], oid_len[i],
					   &acpi_info[i], &size, NULL, 0) < 0)
					return;
				}
			available = (acpi_info[ACPI_BATT_STATE] != ACPI_BATT_STAT_NOT_PRESENT);
			on_line = acpi_info[ACPI_ACLINE];
			charging = (acpi_info[ACPI_BATT_STATE] == ACPI_BATT_STAT_CHARGING);
			percent = acpi_info[ACPI_BATT_LIFE];
			if (acpi_info[ACPI_BATT_TIME] == 0 && percent > 0)
				time_left = -1;
			else
				time_left = acpi_info[ACPI_BATT_TIME];
			gkrellm_battery_assign_data(
				GKRELLM_BATTERY_COMPOSITE_ID, available,
				on_line, charging, percent, time_left);
			return;
		}

	if ((f = open(APMDEV, O_RDONLY)) == -1)
		return;
	if ((r = ioctl(f, APMIO_GETINFO, &info)) == -1) {
		close(f);
		return;
	}

	available = (info.ai_batt_stat != L_UNKNOWN ||
		     info.ai_acline == L_ON_LINE);
	on_line = (info.ai_acline == L_ON_LINE) ? TRUE : FALSE;
	charging = (info.ai_batt_stat == L_CHARGING) ? TRUE : FALSE;
	percent = info.ai_batt_life;
#if defined(APM_GETCAPABILITIES)
	if (info.ai_batt_time == -1 || (info.ai_batt_time == 0 && percent > 0))
		time_left = -1;
	else
		time_left = info.ai_batt_time / 60;
#else
	time_left = -1;
#endif
	gkrellm_battery_assign_data(GKRELLM_BATTERY_COMPOSITE_ID, available,
				    on_line, charging, percent, time_left);

#if defined(APMIO_GETPWSTATUS)
	if (info.ai_infoversion >= 1 && info.ai_batteries != (u_int) -1 &&
	    info.ai_batteries > 1)
		{
		gint i;
		struct apm_pwstatus aps;

		for (i = 0; i < info.ai_batteries; ++i)
			{
			bzero(&aps, sizeof(aps));
			aps.ap_device = PMDV_BATT0 + i;
			if (ioctl(f, APMIO_GETPWSTATUS, &aps) == -1 ||
			    (aps.ap_batt_flag != 255 &&
			     (aps.ap_batt_flag & APM_BATT_NOT_PRESENT)))
				continue;
			available = (aps.ap_batt_stat != L_UNKNOWN ||
				     aps.ap_acline == L_ON_LINE);
			on_line = (aps.ap_acline == L_ON_LINE) ? TRUE : FALSE;
			charging = (aps.ap_batt_stat == L_CHARGING) ?
				TRUE : FALSE;
			percent = aps.ap_batt_life;
			if (aps.ap_batt_time == -1 ||
			    (aps.ap_batt_time == 0 && percent > 0))
				time_left = -1;
			else
				time_left = aps.ap_batt_time / 60;
			gkrellm_battery_assign_data(batt_num++, available,
						    on_line, charging, percent,
						    time_left);
			}
		}
#endif

	close(f);
	}

gboolean
gkrellm_sys_battery_init(void)
	{
	return TRUE;
	}

#else

void
gkrellm_sys_battery_read_data(void)
	{
	}

gboolean
gkrellm_sys_battery_init(void)
	{
	return FALSE;
	}

#endif


/* ===================================================================== */
/* Sensor monitor interface */

#if defined(__i386__)

typedef struct
	{
	gchar	*name;
	gfloat	factor;
	gfloat	offset;
	gchar	*vref;
	}
	VoltDefault;

  /* Tables of voltage correction factors and offsets derived from the
  |  compute lines in sensors.conf.  See the README file.
  */
	/* "lm78-*" "lm78-j-*" "lm79-*" "w83781d-*" "sis5595-*" "as99127f-*" */
	/* Values from LM78/LM79 data sheets	*/
static VoltDefault	voltdefault0[] =
	{
	{ "Vcor1",	1.0,    0, NULL },
	{ "Vcor2",	1.0,    0, NULL },
	{ "+3.3V",	1.0,    0, NULL },
	{ "+5V",	1.68,   0, NULL },		/* in3 ((6.8/10)+1)*@	*/
	{ "+12V",	4.0,    0, NULL },		/* in4 ((30/10)+1)*@	*/
	{ "-12V",	-4.0,   0, NULL },		/* in5 -(240/60)*@		*/
	{ "-5V",	-1.667, 0, NULL }		/* in6 -(100/60)*@		*/
	};

#include <dirent.h>
#include <osreldate.h>
#include <machine/cpufunc.h>
#if (__DragonFly_version < 200700)
#include <machine/smb.h>
#else
#include <bus/smbus/smb.h>
#endif

/* Interface types */
#define INTERFACE_IO		0
#define INTERFACE_SMB		1
#define INTERFACE_ACPI		2

/* Addresses to use for /dev/io */
#define WBIO1			0x295
#define WBIO2			0x296

/* LM78/79 addresses */
#define LM78_VOLT(val)		(0x20 + (val))
#define LM78_TEMP		0x27
#define LM78_FAN(val)		(0x28 + (val))
#define LM78_FANDIV		0x47

#define	SENSORS_DIR		"/dev"

#define TZ_ZEROC		2732
#define TZ_KELVTOC(x)		((gfloat)((x) - TZ_ZEROC) / 10.0)


static gint
get_data(int iodev, u_char command, int interface, u_char *ret)
	{
	u_char byte = 0;

	if (interface == INTERFACE_IO)
		{
		outb(WBIO1, command);
		byte = inb(WBIO2);
		}
	else if (interface == INTERFACE_SMB)
		{
		struct smbcmd cmd;

		bzero(&cmd, sizeof(cmd));
		cmd.data.byte_ptr = &byte;
		cmd.slave         = 0x5a;
		cmd.cmd           = command;
		if (ioctl(iodev, SMB_READB, (caddr_t)&cmd) == -1)
			{
			close(iodev);
			return FALSE;
			}
		}
	else
		{
		return FALSE;
		}
	if (byte == 0xff)
		return FALSE;
	*ret = byte;
	return TRUE;
	}

gboolean
gkrellm_sys_sensors_get_temperature(gchar *path, gint id,
		gint iodev, gint interface, gfloat *temp)

	{
	u_char byte;

	if (interface == MBMON_INTERFACE)
		{
		gkrellm_sys_sensors_mbmon_check(FALSE);
		return gkrellm_sys_sensors_mbmon_get_value(path, temp);
		}

	if (interface == INTERFACE_ACPI)
		{
		int value;
		size_t size = sizeof(value);

		if (sysctlbyname(path, &value, &size, NULL, 0) < 0)
			return FALSE;
		if (temp)
			*temp = (gfloat) TZ_KELVTOC(value);
		return TRUE;
		}
	if (get_data(iodev, LM78_TEMP, interface, &byte))
		{
		if (temp)
			*temp = (gfloat) byte;
		return TRUE;
		}
	return FALSE;
	}

gboolean
gkrellm_sys_sensors_get_fan(gchar *path, gint id,
		gint iodev, gint interface, gfloat *fan)
	{
	u_char byte;

	if (interface == MBMON_INTERFACE)
		{
		gkrellm_sys_sensors_mbmon_check(FALSE);
		return gkrellm_sys_sensors_mbmon_get_value(path, fan);
		}

	if (get_data(iodev, LM78_FAN(id), interface, &byte))
		{
		if (byte == 0)
			return FALSE;
		if (fan)
			*fan = 1.35E6 / (gfloat) byte;
		return TRUE;
		}
	return FALSE;
	}

gboolean
gkrellm_sys_sensors_get_voltage(gchar *path, gint id,
		gint iodev, gint interface, gfloat *volt)
	{
	u_char byte;

	if (interface == MBMON_INTERFACE)
		{
		gkrellm_sys_sensors_mbmon_check(FALSE);
		return gkrellm_sys_sensors_mbmon_get_value(path, volt);
		}

	if (get_data(iodev, LM78_VOLT(id), interface, &byte))
		{
		if (volt)
			*volt = (gfloat) byte / 64.0;
		return TRUE;
		}
	return FALSE;
	}

struct freebsd_sensor {
	gint type;
	gchar *id_name;
	gint id;
	gint iodev;
	gint inter;
	gfloat factor;
	gfloat offset;
	gchar *default_label;
};

static GList	*freebsd_sensor_list;

gboolean
gkrellm_sys_sensors_init(void)
	{
	gchar		mib_name[256], label[8];
	gint		interface, id;
	int		oid_acpi_temp[CTL_MAXNAME + 2];
	size_t		oid_acpi_temp_len = sizeof(oid_acpi_temp);
	GList		*list;
	struct freebsd_sensor *sensor;

	/* Do intial daemon reads to get sensors loaded into sensors.c
	*/
	gkrellm_sys_sensors_mbmon_check(TRUE);

	for (id = 0;;)
	{
		snprintf(mib_name, sizeof(mib_name),
			 "hw.acpi.thermal.tz%d.temperature", id);
		if (gk_sysctlnametomib(mib_name, oid_acpi_temp,
				       &oid_acpi_temp_len) < 0)
			break;
		interface = INTERFACE_ACPI;
		if (!gkrellm_sys_sensors_get_temperature(mib_name, 0, 0,
							 interface, NULL))
			continue;
		snprintf(label, sizeof(label), "tz%d", id);
		gkrellm_sensors_add_sensor(SENSOR_TEMPERATURE, NULL,
					   mib_name, 0, 0,
					   interface, 1.0, 0.0, NULL, label);
	}

	if (freebsd_sensor_list)
		{
		for (list = freebsd_sensor_list; list; list = list->next)
			{
			sensor = (struct freebsd_sensor *)list->data;
			gkrellm_sensors_add_sensor(sensor->type, NULL,
					sensor->id_name, sensor->id,
					sensor->iodev, sensor->inter,
					sensor->factor, sensor->offset,
					NULL, sensor->default_label);
			}
		}

	return (TRUE);
	}

static gboolean
sensors_add_sensor(gint type, gchar *id_name, gint id, gint iodev, gint inter,
		   gfloat factor, gfloat offset, gchar *default_label)
{
	struct freebsd_sensor *sensor;

	if ((sensor = g_new0(struct freebsd_sensor, 1)) == NULL)
		return FALSE;
	sensor->type = type;
	sensor->id_name = g_strdup(id_name);
	sensor->id = id;
	sensor->iodev = iodev;
	sensor->inter = inter;
	sensor->factor = factor;
	sensor->offset = offset;
	sensor->default_label = default_label ? g_strdup(default_label) : NULL;
	if (g_list_append(freebsd_sensor_list, sensor) == NULL) {
		g_free(sensor->id_name);
		if (sensor->default_label)
			g_free(sensor->default_label);
		g_free(sensor);
		return FALSE;
	}
	return TRUE;
}

static void
scan_for_sensors(void)
	{
	gchar		*chip_dir = SENSORS_DIR;
	DIR		*dir;
	struct dirent	*dentry;
	gchar		temp_file[256], id_name[8];
	gint		iodev = -1, interface = -1, id;
	gint		fandiv[3];
	u_char		byte;
	gboolean	found_sensors = FALSE;

	if ((dir = opendir(chip_dir)) != NULL)
		{
		while ((dentry = readdir(dir)) != NULL)
			{
			if (dentry->d_name[0] == '.' || dentry->d_ino <= 0)
				continue;
			if (strncmp(dentry->d_name, "smb", 3) != 0)
				continue;
			snprintf(temp_file, sizeof(temp_file), "%s/%s",
						chip_dir, dentry->d_name);
			if ((iodev = open(temp_file, O_RDWR)) == -1)
				continue;
			sprintf(id_name, "%s%3s", "temp", dentry->d_name + 3);
			interface = INTERFACE_SMB;
			if (!gkrellm_sys_sensors_get_temperature(NULL, 0, iodev,
					interface, NULL))
				{
				close(iodev);
				continue;
				}
			sensors_add_sensor(SENSOR_TEMPERATURE, id_name, 0,
					iodev, interface, 1.0, 0.0, NULL);
			found_sensors = TRUE;
			break;
			}
		closedir(dir);
		}
	if (!found_sensors)
		{
		snprintf(temp_file, sizeof(temp_file), "%s/%s",
			 chip_dir, "io");
		if ((iodev = open(temp_file, O_RDWR)) == -1)
			return;
		interface = INTERFACE_IO;
		if (!gkrellm_sys_sensors_get_temperature(NULL, 0, iodev,
				interface, NULL))
			{
			close(iodev);
			return;
			}
		sensors_add_sensor(SENSOR_TEMPERATURE, "temp0", 0, iodev,
				interface, 1.0, 0.0, NULL);
		found_sensors = TRUE;
		}
	if (found_sensors)
		{
		if (get_data(iodev, LM78_FANDIV, interface, &byte))
			{
			fandiv[0] = 1 << ((byte & 0x30) >> 4);
			fandiv[1] = 1 << ((byte & 0xc0) >> 6);
			fandiv[2] = 2;
			for (id = 0; id < 3; ++id)
				{
				if (!gkrellm_sys_sensors_get_fan(NULL, id, iodev,
						interface, NULL))
					continue;
				sprintf(id_name, "%s%d", "fan", id);
				sensors_add_sensor(SENSOR_FAN, id_name, id,
						iodev, interface,
						1.0 / (gfloat) fandiv[id], 0.0,
						NULL);
				}
			}
		for (id = 0; id < 7; ++id)
			{
			if (!gkrellm_sys_sensors_get_voltage(NULL, id, iodev,
					interface, NULL))
				continue;
			sprintf(id_name, "%s%d", "in", id);
			sensors_add_sensor(SENSOR_VOLTAGE, id_name, id,
					iodev, interface,
					voltdefault0[id].factor, 0.0,
					voltdefault0[id].name);
			}
		}
	}

#else

gboolean
gkrellm_sys_sensors_get_temperature(gchar *path, gint id,
		gint iodev, gint interface, gfloat *temp)

	{
	return FALSE;
	}

gboolean
gkrellm_sys_sensors_get_fan(gchar *path, gint id,
		gint iodev, gint interface, gfloat *fan)
	{
	return FALSE;
	}

gboolean
gkrellm_sys_sensors_get_voltage(gchar *path, gint id,
		gint iodev, gint interface, gfloat *volt)
	{
	return FALSE;
	}

gboolean
gkrellm_sys_sensors_init(void)
	{
	return FALSE;
	}

#endif
