$NetBSD: patch-gcc_gcc.c,v 1.2 2015/01/01 01:29:56 ryoon Exp $

Add %M spec string.
From pkgsrc/lang/gcc47/patches/patch-gcc_gcc.c

--- gcc/gcc.c.orig	2013-01-14 16:35:23.000000000 +0000
+++ gcc/gcc.c
@@ -609,7 +609,7 @@ proper position among the other output f
 
 #ifndef LINK_PIE_SPEC
 #ifdef HAVE_LD_PIE
-#define LINK_PIE_SPEC "%{pie:-pie} "
+#define LINK_PIE_SPEC "%{pie:-pie} %{p|pg|nopie:-nopie} "
 #else
 #define LINK_PIE_SPEC "%{pie:} "
 #endif
@@ -5101,6 +5101,13 @@ do_spec_1 (const char *spec, int inswitc
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
