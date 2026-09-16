$NetBSD: patch-gcc_config_darwin-driver.cc,v 1.2 2026/09/16 09:06:02 tnn Exp $

- Support Darwin/aarch64.
  https://github.com/Homebrew/homebrew-core/blob/main/Patches/gcc/gcc-15.3.0.diff
- Backport macOS 27 fix:
  https://gcc.gnu.org/git/?p=gcc.git;a=patch;h=bd4b33d265d44bfb3222c7bb962818179242bf4b

--- gcc/config/darwin-driver.cc.orig	2026-06-12 06:09:06.164518915 +0000
+++ gcc/config/darwin-driver.cc
@@ -64,7 +64,7 @@ validate_macosx_version_min (const char
 
   major = strtoul (version_str, &end, 10);
 
-  /* macOS 10, 11, 12, 13, 14, 15 and 26 are known.
+  /* macOS 10 to 15 and 26 upwards are known.
      clang accepts up to 99.  */
   if (major < 10 || major > 99)
     return NULL;
@@ -160,15 +160,16 @@ darwin_find_version_from_kernel (void)
   if (*version_p++ != '.')
     goto parse_failed;
 
-  /* Darwin25 saw a transition to macOS 26.  */
-  if (major_vers >= 25)
+  /* macOS 27 aligned version number with Darwin27.  */
+  if (major_vers >= 27)
     /* Apple clang doesn't include the minor version or the patch level
        in the object file, nor does it pass it to ld  */
+    asprintf (&new_flag, "%d.00.00", major_vers);
+  /* Darwin25 saw a transition to macOS 26.  */
+  else if (major_vers >= 25)
     asprintf (&new_flag, "%d.00.00", major_vers + 1);
   /* Darwin20 saw a transition to macOS 11.  */
   else if (major_vers >= 20)
-    /* Apple clang doesn't include the minor version or the patch level
-       in the object file, nor does it pass it to ld  */
     asprintf (&new_flag, "%d.00.00", major_vers - 9);
   else if (major_vers - 4 <= 4)
     /* On 10.4 and earlier, the old linker is used which does not
@@ -270,10 +271,13 @@ darwin_driver_init (unsigned int *decode
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
@@ -298,6 +302,12 @@ darwin_driver_init (unsigned int *decode
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
@@ -311,7 +321,7 @@ darwin_driver_init (unsigned int *decode
 	  --i;
 	  --*decoded_options_count;
 	  break;
-
+#if !DARWIN_ARM64
 	case OPT_m32:
 	  seenM32 = true;
 	  break;
@@ -319,6 +329,7 @@ darwin_driver_init (unsigned int *decode
 	case OPT_m64:
 	  seenM64 = true;
 	  break;
+#endif
 
 	case OPT_mmacosx_version_min_:
 	  seen_version_min = true;
@@ -378,6 +389,9 @@ darwin_driver_init (unsigned int *decode
   if (seenPPC || seenPPC64)
     warning (0, "this compiler does not support PowerPC"
 		" (%<-arch%> option ignored)");
+  else if (seenArm64)
+    warning (0, "this compiler does not support Arm64"
+		" (%<-arch%> option ignored)");
   if (seenX86)
     {
       if (seenX86_64 || seenM64)
@@ -401,6 +415,9 @@ darwin_driver_init (unsigned int *decode
   if (seenX86 || seenX86_64)
     warning (0, "this compiler does not support x86"
 		" (%<-arch%> option ignored)");
+  else if (seenArm64)
+    warning (0, "this compiler does not support Arm64"
+		" (%<-arch%> option ignored)");
   if (seenPPC)
     {
       if (seenPPC64 || seenM64)
@@ -420,12 +437,20 @@ darwin_driver_init (unsigned int *decode
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
@@ -435,6 +460,7 @@ darwin_driver_init (unsigned int *decode
       generate_option (appendM32 ? OPT_m32 : OPT_m64, NULL, 1, CL_DRIVER,
 		       &(*decoded_options)[*decoded_options_count - 1]);
     }
+#endif
 
   if (!seen_sysroot_p)
     {
