$NetBSD: patch-imake.c,v 1.4 2013/07/23 06:48:21 wiz Exp $

--- imake.c.orig	2013-07-23 04:53:04.000000000 +0000
+++ imake.c
@@ -1337,54 +1337,8 @@ get_gcc_version(FILE *inFile, char *name
 static boolean
 get_gcc(char *cmd)
 {
-  struct stat sb;
-    static const char* gcc_path[] = {
-#if defined(linux) || \
-     defined(__NetBSD__) || \
-     defined(__OpenBSD__) || \
-     defined(__FreeBSD__) || \
-     defined(__DragonFly__) || \
-     defined(__APPLE__) || \
-     defined(__CYGWIN__) || \
-     defined(__MINGW32__) || \
-     defined(__GNU__) || \
-     defined(__GLIBC__)
-	"/usr/bin/cc",	/* for Linux PostIncDir */
-#endif
-	"/usr/local/bin/gcc",
-	"/opt/gnu/bin/gcc",
-	"/usr/pkg/bin/gcc"
-    };
-
-#ifdef CROSSCOMPILE
-    static const char* cross_cc_name[] = {
-	"cc",
-	"gcc"
-    };
-
-    if (CrossCompiling) {
-	int i;
-	for (i = 0; i < sizeof (cross_cc_name) / sizeof cross_cc_name[0]; i++){
-	    strcpy (cmd, CrossCompileDir);
-	    strcat (cmd, "/");
-	    strcat (cmd, cross_cc_name[i]);
-	    if (lstat (cmd, &sb) == 0) {
-		return TRUE;
-		break;
-	    }
-	}
-    } else
-#endif
-      {
-	int i;
-	for (i = 0; i < sizeof (gcc_path) / sizeof gcc_path[0]; i++) {
-	    if (lstat (gcc_path[i], &sb) == 0) {
-		strcpy (cmd, gcc_path[i]);
-		return TRUE;
-	    }
-	}
-      }
-    return FALSE;
+	strcpy(cmd, "gcc");
+	return TRUE;
 }
 
 #ifdef CROSSCOMPILE
