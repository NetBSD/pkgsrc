$NetBSD: patch-src_pulsecore_shm.c,v 1.1 2019/06/23 04:46:21 tsutsui Exp $

- handle NetBSD's shm_open(3) path for pa_shm_cleanup().

--- src/pulsecore/shm.c.orig	2018-07-13 19:06:12.000000000 +0000
+++ src/pulsecore/shm.c
@@ -72,6 +72,9 @@
 #elif defined(__sun)
 #define SHM_PATH "/tmp"
 #define SHM_ID_LEN 15
+#elif defined(__NetBSD__)
+#define SHM_PATH "/var/shm"
+#define SHM_ID_LEN 18
 #else
 #undef SHM_PATH
 #undef SHM_ID_LEN
@@ -445,6 +448,8 @@ int pa_shm_cleanup(void) {
 
 #if defined(__sun)
         if (strncmp(de->d_name, ".SHMDpulse-shm-", SHM_ID_LEN))
+#elif defined(__NetBSD__)
+        if (strncmp(de->d_name, ".shmobj_pulse-shm-", SHM_ID_LEN))
 #else
         if (strncmp(de->d_name, "pulse-shm-", SHM_ID_LEN))
 #endif
