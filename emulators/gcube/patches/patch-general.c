$NetBSD: patch-general.c,v 1.1 2013/03/02 18:13:14 joerg Exp $

--- general.c.orig	2013-03-01 16:14:43.000000000 +0000
+++ general.c
@@ -187,7 +187,7 @@ __u32 round_up (__u32 a, __u32 b)
 }
 
 
-inline int is_power_of_two (__u32 a)
+int is_power_of_two (__u32 a)
 {
 	int i = 0;
 
