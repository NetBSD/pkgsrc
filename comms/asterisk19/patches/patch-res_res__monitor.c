$NetBSD: patch-res_res__monitor.c,v 1.1 2024/07/08 05:03:02 jnemeth Exp $

--- res/res_monitor.c.orig	2024-06-24 05:01:06.426851320 +0000
+++ res/res_monitor.c
@@ -25,7 +25,6 @@
 
 /*** MODULEINFO
 	<use type="module">func_periodic_hook</use>
-	<defaultenabled>no</defaultenabled>
 	<support_level>deprecated</support_level>
 	<replacement>app_mixmonitor</replacement>
 	<deprecated_in>16</deprecated_in>
