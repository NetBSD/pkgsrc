$NetBSD: patch-fixincludes_fixincl.x,v 1.1 2019/10/19 21:20:38 minskim Exp $

A workaround for Catalina SDK bug from
https://github.com/Homebrew/homebrew-core/pull/44762

--- fixincludes/fixincl.x.orig	2018-02-22 08:12:26.000000000 -0800
+++ fixincludes/fixincl.x	2019-10-18 18:16:11.000000000 -0700
@@ -2584,6 +2584,48 @@
 
 /* * * * * * * * * * * * * * * * * * * * * * * * * *
  *
+ *  Description of Darwin_Availability fix
+ */
+tSCC zDarwin_AvailabilityName[] =
+    "darwin_availability";
+
+/*
+ *  File name selection pattern
+ */
+tSCC zDarwin_AvailabilityList[] =
+  "Availability.h\0";
+/*
+ *  Machine/OS name selection pattern
+ */
+tSCC* apzDarwin_AvailabilityMachs[] = {
+        "*-*-darwin*",
+        (const char*)NULL };
+
+/*
+ *  content selection pattern - do fix if pattern found
+ */
+tSCC zDarwin_AvailabilitySelect0[] =
+       "#endif /\\* __OSX_AVAILABLE_STARTING \\*/";
+
+#define    DARWIN_AVAILABILITY_TEST_CT  1
+static tTestDesc aDarwin_AvailabilityTests[] = {
+  { TT_EGREP,    zDarwin_AvailabilitySelect0, (regex_t*)NULL }, };
+
+/*
+ *  Fix Command Arguments for Darwin_Availability
+ */
+static const char* apzDarwin_AvailabilityPatch[] = {
+    "format",
+    "#endif /* __OSX_AVAILABLE_STARTING */\n\
+#ifndef __OSX_AVAILABLE_STARTING\n\
+  #define __OSX_AVAILABLE_STARTING(_osx, _ios)\n\
+  #define __OSX_AVAILABLE_BUT_DEPRECATED(_osxIntro, _osxDep, _iosIntro, _iosDep)\n\
+  #define __OSX_AVAILABLE_BUT_DEPRECATED_MSG(_osxIntro, _osxDep, _iosIntro, _iosDep, _msg)\n\
+#endif",
+    (char*)NULL };
+
+/* * * * * * * * * * * * * * * * * * * * * * * * * *
+ *
  *  Description of Darwin_9_Long_Double_Funcs_2 fix
  */
 tSCC zDarwin_9_Long_Double_Funcs_2Name[] =
@@ -10099,9 +10141,9 @@
  *
  *  List of all fixes
  */
-#define REGEX_COUNT          287
+#define REGEX_COUNT          288
 #define MACH_LIST_SIZE_LIMIT 187
-#define FIX_COUNT            249
+#define FIX_COUNT            250
 
 /*
  *  Enumerate the fixes
@@ -10168,6 +10210,7 @@
     CTRL_QUOTES_USE_FIXIDX,
     CXX_UNREADY_FIXIDX,
     DARWIN_AVAILABILITYINTERNAL_FIXIDX,
+    DARWIN_AVAILABILITY_FIXIDX,
     DARWIN_9_LONG_DOUBLE_FUNCS_2_FIXIDX,
     DARWIN_EXTERNC_FIXIDX,
     DARWIN_GCC4_BREAKAGE_FIXIDX,
@@ -10664,6 +10707,11 @@
      DARWIN_AVAILABILITYINTERNAL_TEST_CT, FD_MACH_ONLY | FD_SUBROUTINE,
      aDarwin_AvailabilityinternalTests,   apzDarwin_AvailabilityinternalPatch, 0 },
 
+  {  zDarwin_AvailabilityName,    zDarwin_AvailabilityList,
+     apzDarwin_AvailabilityMachs,
+     DARWIN_AVAILABILITY_TEST_CT, FD_MACH_ONLY | FD_SUBROUTINE,
+     aDarwin_AvailabilityTests,   apzDarwin_AvailabilityPatch, 0 },
+
   {  zDarwin_9_Long_Double_Funcs_2Name,    zDarwin_9_Long_Double_Funcs_2List,
      apzDarwin_9_Long_Double_Funcs_2Machs,
      DARWIN_9_LONG_DOUBLE_FUNCS_2_TEST_CT, FD_MACH_ONLY | FD_SUBROUTINE,
