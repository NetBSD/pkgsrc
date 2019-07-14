$NetBSD: patch-src_ulaw.c,v 1.1 2019/07/14 15:39:32 nia Exp $

Fix: CVE-2018-19661, CVE-2017-17457

Upstream commit:
https://github.com/erikd/libsndfile/commit/8ddc442d539ca775d80cdbc7af17a718634a743f.patch

--- src/ulaw.c.orig	2016-04-01 21:08:53.000000000 +0000
+++ src/ulaw.c
@@ -19,6 +19,7 @@
 #include	"sfconfig.h"
 
 #include	<math.h>
+#include	<limits.h>
 
 #include	"sndfile.h"
 #include	"common.h"
@@ -827,7 +828,9 @@ s2ulaw_array (const short *ptr, int coun
 static inline void
 i2ulaw_array (const int *ptr, int count, unsigned char *buffer)
 {	while (--count >= 0)
-	{	if (ptr [count] >= 0)
+	{	if (ptr [count] == INT_MIN)
+			buffer [count] = ulaw_encode [INT_MAX >> (16 + 2)] ;
+		else if (ptr [count] >= 0)
 			buffer [count] = ulaw_encode [ptr [count] >> (16 + 2)] ;
 		else
 			buffer [count] = 0x7F & ulaw_encode [-ptr [count] >> (16 + 2)] ;
@@ -847,7 +850,9 @@ f2ulaw_array (const float *ptr, int coun
 static inline void
 d2ulaw_array (const double *ptr, int count, unsigned char *buffer, double normfact)
 {	while (--count >= 0)
-	{	if (ptr [count] >= 0)
+	{	if (!isfinite (ptr [count]))
+			buffer [count] = 0 ;
+		else if (ptr [count] >= 0)
 			buffer [count] = ulaw_encode [lrint (normfact * ptr [count])] ;
 		else
 			buffer [count] = 0x7F & ulaw_encode [- lrint (normfact * ptr [count])] ;
