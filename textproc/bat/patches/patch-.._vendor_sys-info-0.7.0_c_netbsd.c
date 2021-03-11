$NetBSD: patch-.._vendor_sys-info-0.7.0_c_netbsd.c,v 1.1 2021/03/11 19:25:04 fox Exp $

Adds NetBSD support for sys-info crate.

This patch has been upstreamed. And will be removed once it is merged.

Upstream PR: https://github.com/FillZpp/sys-info-rs/pull/91

--- ../vendor/sys-info-0.7.0/c/netbsd.c.orig	2021-03-10 06:48:34.899936996 +0000
+++ ../vendor/sys-info-0.7.0/c/netbsd.c
@@ -0,0 +1,140 @@
+#include <sys/param.h>
+#include <sys/proc.h>
+#include <sys/resource.h>
+#include <sys/types.h>
+#include <sys/mount.h>
+#include <sys/swap.h>
+#include <sys/sysctl.h>
+#include <sys/utsname.h>
+#include <pthread.h>
+#include <stdio.h>
+#include <stdlib.h>
+#include <string.h>
+#include <unistd.h>
+#include <kvm.h>
+
+#include <uvm/uvm_extern.h>
+
+#include "info.h"
+
+#define ONE_K 1024L
+#define ONE_DECIMAL_K 1000L
+
+#ifndef PAGE_SIZE
+#define PAGE_SIZE ( sysconf(_SC_PAGESIZE) )
+#endif
+#define PAGE_SIZE_KB ( PAGE_SIZE / ONE_K )
+
+static const char *os_release;
+
+static pthread_once_t once_init_netbsd;
+static void init_netbsd(void) {
+	struct utsname un;
+
+	if (uname(&un) == -1)
+		return;
+	os_release = strdup(un.release);
+}
+
+const char *get_os_release(void) {
+	pthread_once(&once_init_netbsd, init_netbsd);
+	return (os_release);
+}
+
+uint64_t get_cpu_speed(void) {
+	uint64_t tsc_freq;
+	size_t len;
+	int error;
+
+#if defined(__i386__) || defined(__amd64__)
+	len = sizeof(tsc_freq);
+	error = sysctlbyname("machdep.tsc_freq", &tsc_freq, &len, NULL, 0);
+	if (error == -1)
+		return (0);
+#else
+	tsc_freq = ONE_DECIMAL_K * ONE_DECIMAL_K * ONE_DECIMAL_K;
+#endif
+	return (tsc_freq / ONE_DECIMAL_K / ONE_DECIMAL_K);
+}
+
+unsigned long get_proc_total(void) {
+	char errbuf[_POSIX2_LINE_MAX];
+        int count;
+	kvm_t *kd;
+	struct kinfo_proc *kp;
+
+	if ((kd = kvm_openfiles(NULL, NULL, NULL, KVM_NO_FILES, errbuf)) == NULL)
+		return (0);
+
+	if ((kp = kvm_getprocs(kd, KERN_PROC_ALL, 0, &count)) == NULL) {
+		(void) kvm_close(kd);
+		return(0);
+	}
+
+	kvm_close(kd);
+	free(kp);
+	return (unsigned long) (count);
+}
+
+int32_t get_mem_info_bsd(struct MemInfo *mi) {
+	static int uvmexp_mib[] = {CTL_VM, VM_UVMEXP2};
+	struct uvmexp_sysctl uvmexp;
+	size_t size_uvmexp = sizeof(uvmexp);
+	int error;
+
+	error = sysctl(uvmexp_mib, 2, &uvmexp, &size_uvmexp, NULL, 0);
+	if (error == -1)
+		goto fail;
+
+	// These calculations have been taken from sys/miscfs/procfs
+	// They need review for testing the correctness
+	mi->total = (uint64_t)uvmexp.npages * PAGE_SIZE_KB / ONE_K;
+	mi->avail = 0;
+	mi->free = (uint64_t)uvmexp.free * PAGE_SIZE_KB / ONE_K;
+	mi->cached = (uvmexp.anonpages + uvmexp.filepages + uvmexp.execpages) * PAGE_SIZE_KB / ONE_K;
+	mi->buffers = uvmexp.filepages * PAGE_SIZE_KB / ONE_K;
+	mi->swap_total = uvmexp.swpages * PAGE_SIZE_KB / ONE_K;
+	mi->swap_free = (uvmexp.swpages - uvmexp.swpginuse) * PAGE_SIZE_KB / ONE_K;
+	return (0);
+
+fail:
+	return (-1);
+}
+
+int32_t get_disk_info_bsd(DiskInfo *di) {
+	struct statvfs *sfs, *sf;
+	int i, nmounts;
+	uint64_t dtotal, dfree;
+	int32_t res = 0;
+
+	dtotal = 0;
+	dfree = 0;
+	sfs = NULL;
+	res = -1;
+
+	nmounts = getvfsstat(NULL, 0, MNT_WAIT);
+	if (nmounts == -1)
+		goto fail;
+	sfs = calloc(nmounts, sizeof(*sfs));
+	if (sfs == NULL)
+		goto fail;
+	nmounts = getvfsstat(sfs, nmounts * sizeof(*sfs), MNT_WAIT);
+	if (nmounts == -1)
+		goto fail;
+
+	for (i = 0; i < nmounts; i++) {
+		sf = &sfs[i];
+		if ((sf->f_flag & MNT_LOCAL) != MNT_LOCAL)
+			continue;
+		dtotal += sf->f_blocks * sf->f_bsize;
+		dfree += sf->f_bfree * sf->f_bsize;
+	}
+
+	di->total = dtotal / 1000;
+	di->free = dfree / 1000;
+	res = 0;
+
+fail:
+	free(sfs);
+	return (res);
+}
