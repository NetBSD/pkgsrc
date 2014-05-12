$NetBSD: patch-gold_options.h,v 1.1 2014/05/12 16:33:20 marino Exp $

 The NetBSD and OpenBSD real-time linkers do not understand DT_RUNPATH
 or DT_INIT_ARRAY.  The current gold defaults are not suitable for them.
 The last couple of DragonFly and FreeBSD releases do support these tags.

--- gold/options.h.orig	2013-11-04 15:33:39.000000000 +0000
+++ gold/options.h
@@ -716,9 +716,15 @@ class General_options
 	      N_("Output cross reference table"),
 	      N_("Do not output cross reference table"));
 
+#if defined(__NetBSD__) || defined(__OpenBSD__)
+  DEFINE_bool(ctors_in_init_array, options::TWO_DASHES, '\0', false,
+	      N_("Use DT_INIT_ARRAY for all constructors"),
+	      N_("Handle constructors as directed by compiler (default)"));
+#else
   DEFINE_bool(ctors_in_init_array, options::TWO_DASHES, '\0', true,
 	      N_("Use DT_INIT_ARRAY for all constructors (default)"),
 	      N_("Handle constructors as directed by compiler"));
+#endif
 
   DEFINE_bool(define_common, options::TWO_DASHES, 'd', false,
 	      N_("Define common symbols"),
@@ -949,7 +955,11 @@ class General_options
 	      N_("Do not page align data, do not make text readonly"),
 	      N_("Page align data, make text readonly"));
 
+#if defined(__NetBSD__) || defined(__OpenBSD__)
+  DEFINE_enable(new_dtags, options::EXACTLY_TWO_DASHES, '\0', false,
+#else
   DEFINE_enable(new_dtags, options::EXACTLY_TWO_DASHES, '\0', true,
+#endif
 		N_("Enable use of DT_RUNPATH and DT_FLAGS"),
 		N_("Disable use of DT_RUNPATH and DT_FLAGS"));
 
