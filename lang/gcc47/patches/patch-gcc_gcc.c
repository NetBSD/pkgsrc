$NetBSD: patch-gcc_gcc.c,v 1.3 2012/09/15 07:41:24 sbd Exp $

Add %M spec string.

Patch commited to gcc in svn id 187775.

--- gcc/gcc.c.orig	2012-02-28 17:31:38.000000000 +0000
+++ gcc/gcc.c
@@ -5115,6 +5115,13 @@ do_spec_1 (const char *spec, int inswitc
 	      return value;
 	    break;
 
+	  case 'M':
+	    if (multilib_os_dir == NULL)
+	      obstack_1grow (&obstack, '.');
+	    else
+	      obstack_grow (&obstack, multilib_os_dir, strlen(multilib_os_dir));
+	    break;
+
 	  case 'G':
 	    value = do_spec_1 (libgcc_spec, 0, NULL);
 	    if (value != 0)
