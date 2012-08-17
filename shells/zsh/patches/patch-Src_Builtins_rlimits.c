$NetBSD: patch-Src_Builtins_rlimits.c,v 1.1 2012/08/17 10:53:10 wiz Exp $

Add support for thread limits.
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
@@ -791,6 +797,11 @@ bin_ulimit(char *name, char **argv, UNUS
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
