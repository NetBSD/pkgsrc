$NetBSD: patch-imake.c,v 1.5 2014/03/14 21:14:28 asau Exp $

--- imake.c.orig	2013-07-23 04:53:04.000000000 +0000
+++ imake.c
@@ -1158,7 +1158,9 @@ get_binary_format(FILE *inFile)
   } else
       strcpy (cmd, "objformat");
 
-  if (osrel >= 300004 &&
+  if (osrel >= 600000)
+    iself = 1;
+  else if (osrel >= 300004 &&
       (objprog = popen(cmd, "r")) != NULL &&
       fgets(buf, sizeof(buf), objprog) != NULL &&
       strncmp(buf, "elf", 3) == 0)
@@ -1337,54 +1339,8 @@ get_gcc_version(FILE *inFile, char *name
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
