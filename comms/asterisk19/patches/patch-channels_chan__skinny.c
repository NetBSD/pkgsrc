$NetBSD: patch-channels_chan__skinny.c,v 1.1 2024/07/08 05:03:01 jnemeth Exp $

--- channels/chan_skinny.c.orig	2024-06-24 05:00:21.935786725 +0000
+++ channels/chan_skinny.c
@@ -34,7 +34,6 @@
  */
 
 /*** MODULEINFO
-	<defaultenabled>no</defaultenabled>
 	<support_level>deprecated</support_level>
 	<deprecated_in>19</deprecated_in>
 	<removed_in>21</removed_in>
