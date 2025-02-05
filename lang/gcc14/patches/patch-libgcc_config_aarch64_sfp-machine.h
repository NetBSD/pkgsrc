$NetBSD: patch-libgcc_config_aarch64_sfp-machine.h,v 1.1 2025/02/05 16:30:37 adam Exp $

Support Darwin/aarch64, from https://github.com/Homebrew/formula-patches.

--- libgcc/config/aarch64/sfp-machine.h
+++ libgcc/config/aarch64/sfp-machine.h
@@ -124,6 +124,27 @@ void __sfp_handle_exceptions (int);


 /* Define ALIASNAME as a strong alias for NAME.  */
+#if defined __APPLE__
+/* Mach-O doesn't support aliasing, so we build a secondary function for
+   the alias - we need to do a bit of a dance to find out what the type of
+   the arguments is and then apply that to the secondary function.
+   If these functions ever return anything but CMPtype we need to revisit
+   this... */
+typedef float alias_HFtype __attribute__ ((mode (HF)));
+typedef float alias_SFtype __attribute__ ((mode (SF)));
+typedef float alias_DFtype __attribute__ ((mode (DF)));
+typedef float alias_TFtype __attribute__ ((mode (TF)));
+#define ALIAS_SELECTOR \
+  CMPtype (*) (alias_HFtype, alias_HFtype): (alias_HFtype) 0, \
+  CMPtype (*) (alias_SFtype, alias_SFtype): (alias_SFtype) 0, \
+  CMPtype (*) (alias_DFtype, alias_DFtype): (alias_DFtype) 0, \
+  CMPtype (*) (alias_TFtype, alias_TFtype): (alias_TFtype) 0
+#define strong_alias(name, aliasname) \
+  CMPtype aliasname (__typeof (_Generic (name, ALIAS_SELECTOR)) a, \
+		     __typeof (_Generic (name, ALIAS_SELECTOR)) b) \
+		    { return name (a, b); }
+#else
 # define strong_alias(name, aliasname) _strong_alias(name, aliasname)
 # define _strong_alias(name, aliasname) \
   extern __typeof (name) aliasname __attribute__ ((alias (#name)));
+#endif
