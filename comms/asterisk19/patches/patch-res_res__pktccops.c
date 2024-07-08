$NetBSD: patch-res_res__pktccops.c,v 1.1 2024/07/08 05:03:02 jnemeth Exp $

--- res/res_pktccops.c.orig	2024-06-24 05:01:44.902431891 +0000
+++ res/res_pktccops.c
@@ -31,7 +31,6 @@
  */
 
 /*** MODULEINFO
-        <defaultenabled>no</defaultenabled>
 	<support_level>deprecated</support_level>
 	<deprecated_in>19</deprecated_in>
 	<removed_in>21</removed_in>
