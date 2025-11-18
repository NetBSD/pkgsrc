$NetBSD: patch-t_unit-tests_clar_clar_sandbox.h,v 1.2 2025/11/18 16:24:48 adam Exp $

--- t/unit-tests/clar/clar/sandbox.h.orig	2025-11-17 16:38:17.000000000 +0000
+++ t/unit-tests/clar/clar/sandbox.h
@@ -164,7 +164,7 @@ static int build_tempdir_path(void)
 
 	if (mkdir(_clar_tempdir, 0700) != 0)
 		return -1;
-#elif defined(__sun) || defined(__TANDEM) || defined(__hpux)
+#elif defined(__sun) || defined(__TANDEM) || defined(__hpux) || defined(__QNX__)
 	if (mktemp(_clar_tempdir) == NULL)
 		return -1;
 
