$NetBSD: patch-vendor_libc-0.2.175_src_unix_bsd_netbsdlike_netbsd_mod.rs,v 1.1 2026/04/02 19:06:34 wiz Exp $

Use __pthread_spin_t to define pthread_spin_t, not c_uchar which
isn't universally this type on the various NetBSD targets.

--- vendor/libc-0.2.175/src/unix/bsd/netbsdlike/netbsd/mod.rs.orig	2025-12-28 21:19:19.046785602 +0000
+++ vendor/libc-0.2.175/src/unix/bsd/netbsdlike/netbsd/mod.rs
@@ -15,7 +15,7 @@ pub type lwpid_t = c_uint;
 pub type shmatt_t = c_uint;
 pub type cpuid_t = c_ulong;
 pub type cpuset_t = _cpuset;
-pub type pthread_spin_t = c_uchar;
+pub type pthread_spin_t = __pthread_spin_t;
 pub type timer_t = c_int;
 
 // elf.h
