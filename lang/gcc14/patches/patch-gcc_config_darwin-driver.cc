$NetBSD: patch-gcc_config_darwin-driver.cc,v 1.1 2025/02/05 16:30:35 adam Exp $

Support Darwin/aarch64, from https://github.com/Homebrew/formula-patches.

--- gcc/config/darwin-driver.cc.orig	2024-08-01 08:17:14.000000000 +0000
+++ gcc/config/darwin-driver.cc
@@ -268,10 +268,13 @@ darwin_driver_init (unsigned int *decode
   bool seenX86_64 = false;
   bool seenPPC = false;
   bool seenPPC64 = false;
+#if !DARWIN_ARM64
+  bool seenArm64 = false;
   bool seenM32 = false;
   bool seenM64 = false;
   bool appendM32 = false;
   bool appendM64 = false;
+#endif
   const char *vers_string = NULL;
   bool seen_version_min = false;
   bool seen_sysroot_p = false;
@@ -296,6 +299,12 @@ darwin_driver_init (unsigned int *decode
 	    seenPPC = true;
 	  else if (!strcmp ((*decoded_options)[i].arg, "ppc64"))
 	    seenPPC64 = true;
+	  else if (!strcmp ((*decoded_options)[i].arg, "arm64"))
+#if !DARWIN_ARM64
+	    seenArm64 = true;
+#else
+	    ; /* We accept the option, but don't need to act on it.  */
+#endif
 	  else
 	    error ("this compiler does not support %qs",
 		   (*decoded_options)[i].arg);
@@ -309,7 +318,7 @@ darwin_driver_init (unsigned int *decode
 	  --i;
 	  --*decoded_options_count; 
 	  break;
-
+#if !DARWIN_ARM64
 	case OPT_m32:
 	  seenM32 = true;
 	  break;
@@ -317,6 +326,7 @@ darwin_driver_init (unsigned int *decode
 	case OPT_m64:
 	  seenM64 = true;
 	  break;
+#endif
 
 	case OPT_mmacosx_version_min_:
 	  seen_version_min = true;
@@ -366,6 +376,9 @@ darwin_driver_init (unsigned int *decode
   if (seenPPC || seenPPC64)
     warning (0, "this compiler does not support PowerPC"
 		" (%<-arch%> option ignored)");
+  else if (seenArm64)
+    warning (0, "this compiler does not support Arm64"
+		" (%<-arch%> option ignored)");
   if (seenX86)
     {
       if (seenX86_64 || seenM64)
@@ -389,6 +402,9 @@ darwin_driver_init (unsigned int *decode
   if (seenX86 || seenX86_64)
     warning (0, "this compiler does not support x86"
 		" (%<-arch%> option ignored)");
+  else if (seenArm64)
+    warning (0, "this compiler does not support Arm64"
+		" (%<-arch%> option ignored)");
   if (seenPPC)
     {
       if (seenPPC64 || seenM64)
@@ -408,12 +424,20 @@ darwin_driver_init (unsigned int *decode
       if (! seenM64) /* Add -m64 if the User didn't. */
 	appendM64 = true;
     }
+#elif DARWIN_ARM64
+  if (seenPPC || seenPPC64)
+    warning (0, "this compiler does not support PowerPC"
+		" (%<-arch%> option ignored)");
+  if (seenX86 || seenX86_64)
+    warning (0, "this compiler does not support x86"
+		" (%<-arch%> option ignored)");
 #endif
 
   /* If there is nothing else on the command line, do not add sysroot etc.  */
   if (*decoded_options_count <= 1)
     return;
 
+#if !DARWIN_ARM64
   if (appendM32 || appendM64)
     {
       ++*decoded_options_count;
@@ -423,6 +447,7 @@ darwin_driver_init (unsigned int *decode
       generate_option (appendM32 ? OPT_m32 : OPT_m64, NULL, 1, CL_DRIVER,
 		       &(*decoded_options)[*decoded_options_count - 1]);
     }
+#endif
 
   if (!seen_sysroot_p)
     {
