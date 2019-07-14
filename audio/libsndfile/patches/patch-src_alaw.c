$NetBSD: patch-src_alaw.c,v 1.1 2019/07/14 15:39:32 nia Exp $

Fix: CVE-2018-19662, CVE-2017-17456

Upstream commit:
https://github.com/erikd/libsndfile/commit/8ddc442d539ca775d80cdbc7af17a718634a743f.patch

--- src/alaw.c.orig	2016-04-01 21:08:52.000000000 +0000
+++ src/alaw.c
@@ -19,6 +19,7 @@
 #include	"sfconfig.h"
 
 #include	<math.h>
+#include	<limits.h>
 
 #include	"sndfile.h"
 #include	"common.h"
@@ -326,7 +327,9 @@ s2alaw_array (const short *ptr, int coun
 static inline void
 i2alaw_array (const int *ptr, int count, unsigned char *buffer)
 {	while (--count >= 0)
-	{	if (ptr [count] >= 0)
+	{	if (ptr [count] == INT_MIN)
+			buffer [count] = alaw_encode [INT_MAX >> (16 + 4)] ;
+		else if (ptr [count] >= 0)
 			buffer [count] = alaw_encode [ptr [count] >> (16 + 4)] ;
 		else
 			buffer [count] = 0x7F & alaw_encode [- ptr [count] >> (16 + 4)] ;
@@ -346,7 +349,9 @@ f2alaw_array (const float *ptr, int coun
 static inline void
 d2alaw_array (const double *ptr, int count, unsigned char *buffer, double normfact)
 {	while (--count >= 0)
-	{	if (ptr [count] >= 0)
+	{	if (!isfinite (ptr [count]))
+			buffer [count] = 0 ;
+		else if (ptr [count] >= 0)
 			buffer [count] = alaw_encode [lrint (normfact * ptr [count])] ;
 		else
 			buffer [count] = 0x7F & alaw_encode [- lrint (normfact * ptr [count])] ;
