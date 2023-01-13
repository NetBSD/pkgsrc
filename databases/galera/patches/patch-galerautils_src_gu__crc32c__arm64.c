$NetBSD: patch-galerautils_src_gu__crc32c__arm64.c,v 1.1 2023/01/13 16:08:03 wiz Exp $

NetBSD support.
https://github.com/codership/galera/pull/632

--- galerautils/src/gu_crc32c_arm64.c.orig	2022-11-02 06:09:14.000000000 +0000
+++ galerautils/src/gu_crc32c_arm64.c
@@ -70,7 +70,7 @@ gu_crc32c_arm64(gu_crc32c_t state, const
 
 #include <sys/auxv.h>
 
-#if defined(__FreeBSD__)
+#if defined(__FreeBSD__) || defined(__NetBSD__)
 /* Imitate getauxval() interface */
 static unsigned long int
 getauxval(unsigned long int const type)
@@ -79,7 +79,7 @@ getauxval(unsigned long int const type)
     if (0 != elf_aux_info(type, &ret, sizeof(ret))) ret = 0;
     return ret;
 }
-#endif /* FreeBSD */
+#endif /* FreeBSD || NetBSD */
 
 #if defined(HWCAP_CRC32)
 #    define GU_AT_HWCAP    AT_HWCAP
