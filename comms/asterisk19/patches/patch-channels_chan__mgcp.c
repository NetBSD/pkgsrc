$NetBSD: patch-channels_chan__mgcp.c,v 1.1 2024/07/08 05:03:01 jnemeth Exp $

--- channels/chan_mgcp.c.orig	2024-06-24 04:59:20.335176364 +0000
+++ channels/chan_mgcp.c
@@ -35,7 +35,6 @@
 
 /*** MODULEINFO
         <use type="module">res_pktccops</use>
-	<defaultenabled>no</defaultenabled>
 	<support_level>deprecated</support_level>
 	<deprecated_in>19</deprecated_in>
 	<removed_in>21</removed_in>
