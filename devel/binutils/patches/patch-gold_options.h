$NetBSD: patch-gold_options.h,v 1.4 2020/12/06 18:07:53 fcambus Exp $

 The NetBSD and OpenBSD real-time linkers do not understand DT_RUNPATH
 or DT_INIT_ARRAY.  The current gold defaults are not suitable for them.
 The last couple of DragonFly and FreeBSD releases do support these tags.

--- gold/options.h.orig	2020-07-24 09:12:20.000000000 +0000
+++ gold/options.h
@@ -772,7 +772,11 @@ class General_options
 	      N_("Output cross reference table"),
 	      N_("Do not output cross reference table"));
 
+#if defined(__NetBSD__) || defined(__OpenBSD__)
+  DEFINE_bool(ctors_in_init_array, options::TWO_DASHES, '\0', false,
+#else
   DEFINE_bool(ctors_in_init_array, options::TWO_DASHES, '\0', true,
+#endif
 	      N_("Use DT_INIT_ARRAY for all constructors"),
 	      N_("Handle constructors as directed by compiler"));
 
@@ -834,7 +838,11 @@ class General_options
 	      N_("Do not create exception frame header"));
 
   // Alphabetized under 'e' because the option is spelled --enable-new-dtags.
+#if defined(__NetBSD__) || defined(__OpenBSD__)
+  DEFINE_enable(new_dtags, options::EXACTLY_TWO_DASHES, '\0', false,
+#else
   DEFINE_enable(new_dtags, options::EXACTLY_TWO_DASHES, '\0', true,
+#endif
 		N_("Enable use of DT_RUNPATH"),
 		N_("Disable use of DT_RUNPATH"));
 
