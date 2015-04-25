$NetBSD: patch-lib9_nan.c,v 1.1 2015/04/25 19:58:32 dholland Exp $

"long" isn't necessarily 32 bits wide.

--- lib9/nan.c~	2000-02-11 17:04:14.000000000 +0000
+++ lib9/nan.c
@@ -16,7 +16,7 @@ NaN(void)
 	union
 	{
 		double	d;
-		long	x[2];
+		uint32_t	x[2];
 	} a;
 
 	a.x[1] = NANEXP;
@@ -30,7 +30,7 @@ isNaN(double d)
 	union
 	{
 		double	d;
-		long	x[2];
+		uint32_t	x[2];
 	} a;
 
 	a.d = d;
@@ -45,7 +45,7 @@ Inf(int sign)
 	union
 	{
 		double	d;
-		long	x[2];
+		uint32_t	x[2];
 	} a;
 
 	a.x[1] = NANEXP;
@@ -61,7 +61,7 @@ isInf(double d, int sign)
 	union
 	{
 		double	d;
-		long	x[2];
+		uint32_t	x[2];
 	} a;
 
 	a.d = d;
