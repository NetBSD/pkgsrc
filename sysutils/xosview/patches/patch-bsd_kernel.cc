$NetBSD: patch-bsd_kernel.cc,v 1.1 2020/05/24 11:24:19 rillig Exp $

Don't fail for unprivileged users.

--- bsd/kernel.cc.orig	2020-02-22 19:33:08.000000000 +0000
+++ bsd/kernel.cc
@@ -219,8 +219,10 @@ OpenKDIfNeeded() {
 	 *  that kernel file.  Otherwise, use the default kernel, by
 	 *  specifying NULL.  */
 	if ((kd = kvm_openfiles((kernelFileName[0] ? kernelFileName : NULL),
-		                    NULL, NULL, O_RDONLY, errstring)) == NULL)
-		err(EX_OSFILE, "OpenKDIfNeeded(): %s", errstring);
+		                    NULL, NULL, O_RDONLY, errstring)) == NULL) {
+		warn("OpenKDIfNeeded(): %s", errstring);
+		return;
+	}
 
 	// Parenthetical note:  FreeBSD kvm_openfiles() uses getbootfile() to get
 	// the correct kernel file if the 1st arg is NULL.  As far as I can see,
