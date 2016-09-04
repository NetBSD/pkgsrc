$NetBSD: patch-imake.c,v 1.7 2016/09/04 21:33:53 dholland Exp $

Beat some sense in.

   - Generate all files into the current (build) directory, not /tmp.
     (hunks 1-2)

   - Do not delete any of the temporary files, to allow analysis after
     build failure. (hunks 3-4, first part of 9)

   - Log the command lines executed. (hunk 6)

   - Warn if scrubbing the Imakefile to alert the user to check if that
     broke it (second part of hunk 9)

Also,

   - Use tradcpp's -debuglog feature to trace what happens in the
     templates (hunk 5)

   - Force ELF for freebsd versions >= 6 (hunk 7)

   - Force use of just "gcc" for pkgsrc, so as to not bypass the
     wrappers (hunk 8)

--- imake.c.orig	2013-08-17 10:11:50.000000000 +0000
+++ imake.c
@@ -303,9 +303,9 @@ void KludgeOutputLine(char **), KludgeRe
 const char *cpp = NULL;
 
 const char	*tmpMakefile;
-const char	*tmpMakefileTemplate = "/tmp/Imf.XXXXXX";
+const char	*tmpMakefileTemplate = ".imake.Makefile.XXXXXX";
 const char	*tmpImakefile;
-const char	*tmpImakefileTemplate = "/tmp/IIf.XXXXXX";
+const char	*tmpImakefileTemplate = ".imake.Imakefile.XXXXXX";
 const char	*make_argv[ ARGUMENTS ] = {
 #ifdef WIN32
     "nmake"
@@ -319,7 +319,7 @@ int	cpp_argindex;
 const char	*Imakefile = NULL;
 const char	*Makefile = "Makefile";
 const char	*Template = "Imake.tmpl";
-const char	*ImakefileC = "Imakefile.c";
+const char	*ImakefileC = ".imake.start.c";
 boolean haveImakefileC = FALSE;
 const char	*cleanedImakefile = NULL;
 const char	*program;
@@ -412,7 +412,8 @@ main(int argc, char *argv[])
 		fd = mkstemp(tmpMakefileName);
 		if (fd == -1 || (tmpfd = fdopen(fd, "w+")) == NULL) {
 		   if (fd != -1) {
-		      unlink(tmpMakefileName); close(fd);
+		      /*unlink(tmpMakefileName);*/
+		      close(fd);
 		   }
 		   LogFatal("Cannot create temporary file %s.", tmpMakefileName);
 		}
@@ -454,12 +455,14 @@ showit(FILE *fd)
 void
 wrapup(void)
 {
+#if 0
 	if (tmpMakefile != Makefile)
 		unlink(tmpMakefile);
 	if (cleanedImakefile && cleanedImakefile != Imakefile)
 		unlink(cleanedImakefile);
 	if (haveImakefileC)
 		unlink(ImakefileC);
+#endif
 }
 
 #ifdef SIGNALRETURNSINT
@@ -488,6 +491,10 @@ init(void)
 	while (cpp_argv[ cpp_argindex ] != NULL)
 		cpp_argindex++;
 
+	/* pkgsrc: generate a debug trace of reading the templates */
+	AddCppArg("-debuglog");
+	AddCppArg(".imake.cpplog");
+
 #if defined CROSSCOMPILE
 	if (sys == netBSD)
 	  if (CrossCompiling) {
@@ -773,6 +780,13 @@ doit(FILE *outfd, const char *cmd, const
 {
 	int		pid;
 	waitType	status;
+	unsigned i;
+
+	fprintf(stderr, "imake: executing:");
+	for (i=0; argv[i]; i++) {
+	   fprintf(stderr, " %s", argv[i]);
+	}
+	fprintf(stderr, "\n");
 
 	/*
 	 * Fork and exec the command.
@@ -1158,7 +1172,9 @@ get_binary_format(FILE *inFile)
   } else
       strcpy (cmd, "objformat");
 
-  if (osrel >= 300004 &&
+  if (osrel >= 600000)
+    iself = 1;
+  else if (osrel >= 300004 &&
       (objprog = popen(cmd, "r")) != NULL &&
       fgets(buf, sizeof(buf), objprog) != NULL &&
       strncmp(buf, "elf", 3) == 0)
@@ -1337,54 +1353,8 @@ get_gcc_version(FILE *inFile, char *name
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
@@ -1795,12 +1765,15 @@ CleanCppInput(const char *imakefile)
 			    outFile = fdopen(fd, "w");
 			if (outFile == NULL) {
 			    if (fd != -1) {
-			       unlink(tmpImakefileName); close(fd);
+			       /*unlink(tmpImakefileName);*/
+			       close(fd);
 			    }
 			    LogFatal("Cannot open %s for write.",
 				tmpImakefileName);
 			}
 #endif
+			fprintf(stderr, "%s: Warning: cleaning Imakefile\n",
+				program);
 			tmpImakefile = tmpImakefileName;
 		    }
 		    writetmpfile(outFile, punwritten, pbuf-punwritten,
