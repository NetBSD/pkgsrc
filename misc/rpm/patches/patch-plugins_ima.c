$NetBSD: patch-plugins_ima.c,v 1.1 2023/05/15 13:52:38 jperkin Exp $

Make plugin effectively a nop on SunOS (lacks lsetxattr).

--- plugins/ima.c.orig	2017-02-16 09:40:09.909649457 +0000
+++ plugins/ima.c
@@ -1,4 +1,6 @@
+#if !defined(__sun)
 #include <sys/xattr.h>
+#endif
 
 #include <rpm/rpmfi.h>
 #include <rpm/rpmte.h>
@@ -31,7 +33,9 @@ static rpmRC ima_psm_post(rpmPlugin plug
 		fpath = rpmfiFN(fi);
 		fsig = rpmfiFSignature(fi, &len);
 		if (fsig) {
+#if !defined(__sun)
 		    lsetxattr(fpath, XATTR_NAME_IMA, fsig, len, 0);
+#endif
 		}
 	    }
 	}
