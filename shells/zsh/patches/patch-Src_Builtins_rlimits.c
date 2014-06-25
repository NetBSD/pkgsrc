$NetBSD: patch-Src_Builtins_rlimits.c,v 1.4 2014/06/25 08:39:11 wiz Exp $

Fix thread limit display in ulimit.
From upstream, Peter Stephenson <p.stephenson@samsung.com>.

--- Src/Builtins/rlimits.c.orig	2013-11-27 19:00:20.000000000 +0000
+++ Src/Builtins/rlimits.c
@@ -32,12 +32,14 @@
 
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
 #endif
 
 enum {
@@ -876,6 +878,11 @@ bin_ulimit(char *name, char **argv, UNUS
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
