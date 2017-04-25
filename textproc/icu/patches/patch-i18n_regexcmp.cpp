$NetBSD: patch-i18n_regexcmp.cpp,v 1.1.2.1 2017/04/25 17:54:53 bsiegert Exp $

Backport upstream changeset 39663
ticket:12930 Fix assertion failure in regex compile.

Use safeIncrement for progressing currentLen in matchStartType

--- i18n/regexcmp.cpp.orig	2016-06-15 18:58:17.000000000 +0000
+++ i18n/regexcmp.cpp
@@ -2637,6 +2637,18 @@ void  RegexCompile::findCaseInsensitiveS
 }
 
 
+// Increment with overflow check.
+// val and delta will both be positive.
+
+static int32_t safeIncrement(int32_t val, int32_t delta) {
+    if (INT32_MAX - val > delta) {
+        return val + delta;
+    } else {
+        return INT32_MAX;
+    }
+}
+
+
 
 
 //------------------------------------------------------------------------------
@@ -2737,7 +2749,7 @@ void   RegexCompile::matchStartType() {
                 fRXPat->fInitialChars->add(URX_VAL(op));
                 numInitialStrings += 2;
             }
-            currentLen++;
+            currentLen = safeIncrement(currentLen, 1);
             atStart = FALSE;
             break;
 
@@ -2750,7 +2762,7 @@ void   RegexCompile::matchStartType() {
                 fRXPat->fInitialChars->addAll(*s);
                 numInitialStrings += 2;
             }
-            currentLen++;
+            currentLen = safeIncrement(currentLen, 1);
             atStart = FALSE;
             break;
 
@@ -2787,7 +2799,7 @@ void   RegexCompile::matchStartType() {
                 fRXPat->fInitialChars->addAll(*s);
                 numInitialStrings += 2;
             }
-            currentLen++;
+            currentLen = safeIncrement(currentLen, 1);
             atStart = FALSE;
             break;
 
@@ -2802,7 +2814,7 @@ void   RegexCompile::matchStartType() {
                 fRXPat->fInitialChars->addAll(sc);
                 numInitialStrings += 2;
             }
-            currentLen++;
+            currentLen = safeIncrement(currentLen, 1);
             atStart = FALSE;
             break;
 
@@ -2819,7 +2831,7 @@ void   RegexCompile::matchStartType() {
                  fRXPat->fInitialChars->addAll(s);
                  numInitialStrings += 2;
             }
-            currentLen++;
+            currentLen = safeIncrement(currentLen, 1);
             atStart = FALSE;
             break;
 
@@ -2836,7 +2848,7 @@ void   RegexCompile::matchStartType() {
                 fRXPat->fInitialChars->addAll(s);
                 numInitialStrings += 2;
             }
-            currentLen++;
+            currentLen = safeIncrement(currentLen, 1);
             atStart = FALSE;
             break;
 
@@ -2855,7 +2867,7 @@ void   RegexCompile::matchStartType() {
                 fRXPat->fInitialChars->addAll(s);
                 numInitialStrings += 2;
             }
-            currentLen++;
+            currentLen = safeIncrement(currentLen, 1);
             atStart = FALSE;
             break;
 
@@ -2879,7 +2891,7 @@ void   RegexCompile::matchStartType() {
                 }
                 numInitialStrings += 2;
             }
-            currentLen++;
+            currentLen = safeIncrement(currentLen, 1);
             atStart = FALSE;
             break;
 
@@ -2895,7 +2907,7 @@ void   RegexCompile::matchStartType() {
                 fRXPat->fInitialChars->complement();
                 numInitialStrings += 2;
             }
-            currentLen++;
+            currentLen = safeIncrement(currentLen, 1);
             atStart = FALSE;
             break;
 
@@ -2975,7 +2987,7 @@ void   RegexCompile::matchStartType() {
                     fRXPat->fInitialStringLen = stringLen;
                 }
 
-                currentLen += stringLen;
+                currentLen = safeIncrement(currentLen, stringLen);
                 atStart = FALSE;
             }
             break;
@@ -3000,7 +3012,7 @@ void   RegexCompile::matchStartType() {
                     fRXPat->fInitialChars->addAll(s);
                     numInitialStrings += 2;  // Matching on an initial string not possible.
                 }
-                currentLen += stringLen;
+                currentLen = safeIncrement(currentLen, stringLen);
                 atStart = FALSE;
             }
             break;
@@ -3258,7 +3270,7 @@ int32_t   RegexCompile::minMatchLength(i
         case URX_DOTANY_ALL:    // . matches one or two.
         case URX_DOTANY:
         case URX_DOTANY_UNIX:
-            currentLen++;
+            currentLen = safeIncrement(currentLen, 1);
             break;
 
 
@@ -3310,7 +3322,7 @@ int32_t   RegexCompile::minMatchLength(i
             {
                 loc++;
                 int32_t stringLenOp = (int32_t)fRXPat->fCompiledPat->elementAti(loc);
-                currentLen += URX_VAL(stringLenOp);
+                currentLen = safeIncrement(currentLen, URX_VAL(stringLenOp));
             }
             break;
 
@@ -3323,7 +3335,7 @@ int32_t   RegexCompile::minMatchLength(i
                 //       Assume a min length of one for now.  A min length of zero causes
                 //        optimization failures for a pattern like "string"+
                 // currentLen += URX_VAL(stringLenOp);
-                currentLen += 1;
+                currentLen = safeIncrement(currentLen, 1);
             }
             break;
 
@@ -3433,18 +3445,6 @@ int32_t   RegexCompile::minMatchLength(i
     return currentLen;
 }
 
-// Increment with overflow check.
-// val and delta will both be positive.
-
-static int32_t safeIncrement(int32_t val, int32_t delta) {
-    if (INT32_MAX - val > delta) {
-        return val + delta;
-    } else {
-        return INT32_MAX;
-    }
-}
-
-
 //------------------------------------------------------------------------------
 //
 //   maxMatchLength    Calculate the length of the longest string that could
