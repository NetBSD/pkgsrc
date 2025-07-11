$NetBSD: patch-Garlic_s-rpc.adb,v 1.1 2025/07/11 06:17:39 dkazankov Exp $

Fix some compilation warnings
https://github.com/reznikmm/garlic/commit/b738f20db65add57f817f952a625df73bef0710e

--- Garlic/s-rpc.adb.orig	2007-11-26 15:10:13.000000000 +0200
+++ Garlic/s-rpc.adb
@@ -48,10 +48,6 @@
 
 package body System.RPC is
 
-   use Ada.Streams;
-
-   use type System.Garlic.Streams.Params_Stream_Access;
-   use type System.Garlic.Streams.Params_Stream_Type;
    use type System.Garlic.Types.Partition_ID;
 
    --  This package needs extra comments ???
