$NetBSD: patch-Src_Builtins_rlimits.c,v 1.5 2014/06/25 12:19:09 wiz Exp $

Fix thread limit display in ulimit.
From upstream, Peter Stephenson <p.stephenson@samsung.com>.

--- Src/Builtins/rlimits.c.orig	2013-11-27 19:00:20.000000000 +0000
+++ Src/Builtins/rlimits.c
@@ -32,12 +32,17 @@
 
 #if defined(HAVE_GETRLIMIT) && defined(RLIM_INFINITY)
 
-#ifdef RLIMIT_POSIXLOCKS
+#if defined(HAVE_RLIMIT_POSIXLOCKS) && !defined(HAVE_RLIMIT_LOCKS)
 #  define RLIMIT_LOCKS		RLIMIT_POSIXLOCKS
+#  define HAVE_RLIMIT_LOCKS     1
 #endif
 
-#ifdef RLIMIT_NTHR
+#if defined(HAVE_RLIMIT_NTHR) && !defined(HAVE_RLIMIT_PTHREAD)
 #  define RLIMIT_PTHREAD	RLIMIT_NTHR
+#  define HAVE_RLIMIT_PTHREAD   1
+#  define THREAD_FMT            "-T: threads                         "
+#else
+#  define THREAD_FMT            "-T: threads per process             "
 #endif
 
 enum {
@@ -373,7 +378,7 @@ printulimit(char *nam, int lim, int hard
 # ifdef HAVE_RLIMIT_PTHREAD
     case RLIMIT_PTHREAD:
 	if (head)
-	    printf("-T: threads per process             ");
+	    printf(THREAD_FMT);
 	break;
 # endif /* HAVE_RLIMIT_PTHREAD */
 # ifdef HAVE_RLIMIT_NICE
@@ -860,6 +865,13 @@ bin_ulimit(char *name, char **argv, UNUS
 		case 'r':
 		    res = RLIMIT_RTPRIO;
 		    break;
+# else
+#  ifdef HAVE_RLIMIT_NTHR
+		    /* For compatibility with sh on NetBSD */
+		case 'r':
+		    res = RLIMIT_NTHR;
+		    break;
+#  endif /* HAVE_RLIMIT_NTHR */
 # endif
 # ifdef HAVE_RLIMIT_NPTS
 		case 'p':
@@ -876,6 +888,11 @@ bin_ulimit(char *name, char **argv, UNUS
 		    res = RLIMIT_KQUEUES;
 		    break;
 # endif
+# ifdef HAVE_RLIMIT_PTHREAD
+		case 'T':
+		    res = RLIMIT_PTHREAD;
+		    break;
+# endif
 		default:
 		    /* unrecognised limit */
 		    zwarnnam(name, "bad option: -%c", *options);
