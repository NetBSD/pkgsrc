$NetBSD: patch-tests_zbufftest.c,v 1.1 2016/09/04 12:36:59 wiz Exp $

https://github.com/facebook/zstd/commit/5153a084f3065229bdcc689dd0cb2d90396b51c2

--- tests/zbufftest.c.orig	2016-08-31 16:09:10.000000000 +0000
+++ tests/zbufftest.c
@@ -23,7 +23,7 @@
 **************************************/
 #include <stdlib.h>       /* free */
 #include <stdio.h>        /* fgets, sscanf */
-#include <sys/timeb.h>    /* timeb */
+#include <time.h>         /* clock_t, clock() */
 #include <string.h>       /* strcmp */
 #include "mem.h"
 #define ZSTD_STATIC_LINKING_ONLY   /* ZSTD_maxCLevel */
@@ -58,13 +58,13 @@ static const U32 prime2 = 2246822519U;
 static U32 g_displayLevel = 2;
 
 #define DISPLAYUPDATE(l, ...) if (g_displayLevel>=l) { \
-            if ((FUZ_GetMilliSpan(g_displayTime) > g_refreshRate) || (g_displayLevel>=4)) \
-            { g_displayTime = FUZ_GetMilliStart(); DISPLAY(__VA_ARGS__); \
+            if ((FUZ_GetClockSpan(g_displayClock) > g_refreshRate) || (g_displayLevel>=4)) \
+            { g_displayClock = clock(); DISPLAY(__VA_ARGS__); \
             if (g_displayLevel>=4) fflush(stdout); } }
-static const U32 g_refreshRate = 150;
-static U32 g_displayTime = 0;
+static const clock_t g_refreshRate = CLOCKS_PER_SEC * 15 / 100;
+static clock_t g_displayClock = 0;
 
-static U32 g_testTime = 0;
+static clock_t g_clockTime = 0;
 
 
 /*-*******************************************************
@@ -72,23 +72,9 @@ static U32 g_testTime = 0;
 *********************************************************/
 #define MAX(a,b) ((a)>(b)?(a):(b))
 
-static U32 FUZ_GetMilliStart(void)
+static clock_t FUZ_GetClockSpan(clock_t clockStart)
 {
-    struct timeb tb;
-    U32 nCount;
-    ftime( &tb );
-    nCount = (U32) (((tb.time & 0xFFFFF) * 1000) +  tb.millitm);
-    return nCount;
-}
-
-
-static U32 FUZ_GetMilliSpan(U32 nTimeStart)
-{
-    U32 const nCurrent = FUZ_GetMilliStart();
-    U32 nSpan = nCurrent - nTimeStart;
-    if (nTimeStart > nCurrent)
-        nSpan += 0x100000 * 1000;
-    return nSpan;
+    return clock() - clockStart;  /* works even when overflow. Max span ~ 30 mn */
 }
 
 /*! FUZ_rand() :
@@ -291,7 +277,7 @@ static int fuzzerTests(U32 seed, U32 nbT
     U32 coreSeed = seed;
     ZBUFF_CCtx* zc;
     ZBUFF_DCtx* zd;
-    U32 startTime = FUZ_GetMilliStart();
+    clock_t startClock = clock();
 
     /* allocations */
     zc = ZBUFF_createCCtx();
@@ -321,7 +307,7 @@ static int fuzzerTests(U32 seed, U32 nbT
         FUZ_rand(&coreSeed);
 
     /* test loop */
-    for ( ; (testNb <= nbTests) || (FUZ_GetMilliSpan(startTime) < g_testTime) ; testNb++ ) {
+    for ( ; (testNb <= nbTests) || (FUZ_GetClockSpan(startClock) < g_clockTime) ; testNb++ ) {
         U32 lseed;
         const BYTE* srcBuffer;
         const BYTE* dict;
@@ -543,7 +529,7 @@ int main(int argc, const char** argv)
 
                 case 'i':
                     argument++;
-                    nbTests=0; g_testTime=0;
+                    nbTests=0; g_clockTime=0;
                     while ((*argument>='0') && (*argument<='9')) {
                         nbTests *= 10;
                         nbTests += *argument - '0';
@@ -553,15 +539,15 @@ int main(int argc, const char** argv)
 
                 case 'T':
                     argument++;
-                    nbTests=0; g_testTime=0;
+                    nbTests=0; g_clockTime=0;
                     while ((*argument>='0') && (*argument<='9')) {
-                        g_testTime *= 10;
-                        g_testTime += *argument - '0';
+                        g_clockTime *= 10;
+                        g_clockTime += *argument - '0';
                         argument++;
                     }
-                    if (*argument=='m') g_testTime *=60, argument++;
+                    if (*argument=='m') g_clockTime *=60, argument++;
                     if (*argument=='n') argument++;
-                    g_testTime *= 1000;
+                    g_clockTime *= CLOCKS_PER_SEC;
                     break;
 
                 case 's':
@@ -605,7 +591,11 @@ int main(int argc, const char** argv)
     /* Get Seed */
     DISPLAY("Starting zstd_buffered tester (%i-bits, %s)\n", (int)(sizeof(size_t)*8), ZSTD_VERSION_STRING);
 
-    if (!seedset) seed = FUZ_GetMilliStart() % 10000;
+    if (!seedset) {
+        time_t const t = time(NULL);
+        U32 const h = XXH32(&t, sizeof(t), 1);
+        seed = h % 10000;
+    }
     DISPLAY("Seed = %u\n", seed);
     if (proba!=FUZ_COMPRESSIBILITY_DEFAULT) DISPLAY("Compressibility : %i%%\n", proba);
 
