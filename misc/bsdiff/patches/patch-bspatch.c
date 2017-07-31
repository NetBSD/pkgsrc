$NetBSD: patch-bspatch.c,v 1.1 2017/07/31 07:09:54 nros Exp $
* Fix CVE-2014-9862
  From the chromium project:
  http://chromium-review.googlesource.com/c/199377/2/dev-util/bsdiff/files/4.3_sanity_check.patch
--- bspatch.c.orig	2005-08-16 22:14:00.000000000 +0000
+++ bspatch.c
@@ -152,6 +152,10 @@ int main(int argc,char * argv[])
 		};
 
 		/* Sanity-check */
+		if ((ctrl[0] < 0) || (ctrl[1] < 0))
+			errx(1,"Corrupt patch\n");
+
+		/* Sanity-check */
 		if(newpos+ctrl[0]>newsize)
 			errx(1,"Corrupt patch\n");
 
