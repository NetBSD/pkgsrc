$NetBSD: patch-gcc_gcc.c,v 1.1.1.1 2012/04/16 04:27:18 sbd Exp $

Add %M spec string.

Submitted to GCC: http://gcc.gnu.org/bugzilla/show_bug.cgi?id=53002

--- gcc/gcc.c.orig	2012-02-28 17:31:38.000000000 +0000
+++ gcc/gcc.c
@@ -5115,6 +5115,10 @@ do_spec_1 (const char *spec, int inswitc
 	      return value;
 	    break;
 
+	  case 'M':
+	    obstack_grow (&obstack, multilib_os_dir, strlen (multilib_os_dir));
+	    break;
+
 	  case 'G':
 	    value = do_spec_1 (libgcc_spec, 0, NULL);
 	    if (value != 0)
