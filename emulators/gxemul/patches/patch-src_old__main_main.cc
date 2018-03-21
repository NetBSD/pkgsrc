$NetBSD: patch-src_old__main_main.cc,v 1.1 2018/03/21 17:39:42 kamil Exp $

Fix C++11 literals.

--- src/old_main/main.cc.orig	2014-08-17 08:45:12.000000000 +0000
+++ src/old_main/main.cc
@@ -228,7 +228,7 @@ void internal_w(char *arg)
 static void usage(int longusage)
 {
 
-	printf("GXemul "VERSION"    "COPYRIGHT_MSG"\n"SECONDARY_MSG);
+	printf("GXemul " VERSION "    " COPYRIGHT_MSG "\n" SECONDARY_MSG);
 	printf("Read the source code and/or documentation for "
 	    "other Copyright messages.\n");
 
@@ -837,7 +837,7 @@ int main(int argc, char *argv[])
 	}
 
 	/*  Print startup message:  */
-	debug("GXemul "VERSION"    "COPYRIGHT_MSG"\n"SECONDARY_MSG
+	debug("GXemul " VERSION "    " COPYRIGHT_MSG "\n" SECONDARY_MSG
 	    "Read the source code and/or documentation for other Copyright "
 	    "messages.\n\n");
 
@@ -932,4 +932,3 @@ int main(int argc, char *argv[])
 
 	return 0;
 }
-
