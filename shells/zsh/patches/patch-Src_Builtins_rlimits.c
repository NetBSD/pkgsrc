$NetBSD: patch-Src_Builtins_rlimits.c,v 1.2 2012/08/17 12:15:37 wiz Exp $

Add support for thread limits and socket buffer size.
From Peter Stephenson <Peter.Stephenson@csr.com> on zsh-workers.

--- Src/Builtins/rlimits.c.orig	2011-11-04 20:47:24.000000000 +0000
+++ Src/Builtins/rlimits.c
@@ -314,6 +314,12 @@ printulimit(char *nam, int lim, int hard
 	    printf("-u: processes                  ");
 	break;
 # endif /* HAVE_RLIMIT_NPROC */
+# ifdef HAVE_RLIMIT_NTHR
+    case RLIMIT_NTHR:
+	if (head)
+	    printf("-r: threads                    ");
+	break;
+#endif /* HAVE_RLIMIT_NTHR */
 # if defined(HAVE_RLIMIT_VMEM) && (!defined(HAVE_RLIMIT_RSS) || !defined(RLIMIT_VMEM_IS_RSS))
     case RLIMIT_VMEM:
 	if (head)
@@ -359,9 +365,7 @@ printulimit(char *nam, int lim, int hard
 # ifdef HAVE_RLIMIT_SBSIZE
     case RLIMIT_SBSIZE:
 	if (head)
-	    printf("-N %2d: socket buffer size (kb) ", RLIMIT_SBSIZE);
-	if (limit != RLIM_INFINITY)
-	    limit /= 1024;
+	    printf("-b: socket buffer size (bytes) ", RLIMIT_SBSIZE);
 	break;
 # endif /* HAVE_RLIMIT_SBSIZE */
 # ifdef HAVE_RLIMIT_PTHREAD
@@ -776,21 +780,31 @@ bin_ulimit(char *name, char **argv, UNUS
 		case 'c':
 		    res = RLIMIT_CORE;
 		    break;
-# ifdef HAVE_RLIMIT_RSS
-		case 'm':
-		    res = RLIMIT_RSS;
+# ifdef HAVE_RLIMIT_SBSIZE
+		case 'b':
+		    res = RLIMIT_SBSIZE;
 		    break;
-# endif /* HAVE_RLIMIT_RSS */
+# endif /* HAVE_RLIMIT_SBSIZE */
 # ifdef HAVE_RLIMIT_MEMLOCK
 		case 'l':
 		    res = RLIMIT_MEMLOCK;
 		    break;
 # endif /* HAVE_RLIMIT_MEMLOCK */
+# ifdef HAVE_RLIMIT_RSS
+		case 'm':
+		    res = RLIMIT_RSS;
+		    break;
+# endif /* HAVE_RLIMIT_RSS */
 # ifdef HAVE_RLIMIT_NOFILE
 		case 'n':
 		    res = RLIMIT_NOFILE;
 		    break;
 # endif /* HAVE_RLIMIT_NOFILE */
+# ifdef HAVE_RLIMIT_NTHR
+		case 'r':
+		    res = RLIMIT_NTHR;
+		    break;
+# endif /* HAVE_RLIMIT_NTHR */
 # ifdef HAVE_RLIMIT_NPROC
 		case 'u':
 		    res = RLIMIT_NPROC;
