$NetBSD: patch-erts_emulator_sys_common_erl__mseg.c,v 1.1 2013/06/08 06:48:24 asau Exp $

--- erts/emulator/sys/common/erl_mseg.c.orig	2013-02-25 19:21:31.000000000 +0000
+++ erts/emulator/sys/common/erl_mseg.c
@@ -439,7 +439,7 @@ mseg_destroy(ErtsMsegAllctr_t *ma, MemKi
 }
 
 #if HAVE_MSEG_RECREATE
-#if defined(__NetBsd__)
+#if defined(__NetBSD__)
 #define MREMAP_FLAGS  (0)
 #else
 #define MREMAP_FLAGS  (MREMAP_MAYMOVE)
