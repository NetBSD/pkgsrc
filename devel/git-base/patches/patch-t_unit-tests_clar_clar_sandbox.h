$NetBSD: patch-t_unit-tests_clar_clar_sandbox.h,v 1.1 2025/10/05 18:09:33 js Exp $

--- t/unit-tests/clar/clar/sandbox.h.orig	2025-08-18 00:35:38.000000000 +0000
+++ t/unit-tests/clar/clar/sandbox.h
@@ -128,7 +128,7 @@ static int build_sandbox_path(void)
 
 	if (mkdir(_clar_path, 0700) != 0)
 		return -1;
-#elif defined(__sun) || defined(__TANDEM)
+#elif defined(__sun) || defined(__TANDEM) || defined(__QNX__)
 	if (mktemp(_clar_path) == NULL)
 		return -1;
 
