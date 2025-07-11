$NetBSD: patch-Garlic_s-garstr.ads,v 1.1 2025/07/11 06:17:38 dkazankov Exp $

Fix some compilation warnings
https://github.com/reznikmm/garlic/commit/b738f20db65add57f817f952a625df73bef0710e

--- Garlic/s-garstr.ads.orig	2007-11-26 15:10:13.000000000 +0200
+++ Garlic/s-garstr.ads
@@ -48,10 +48,10 @@
    type Node_Ptr is access Node;
 
    type Node (Size : Ada.Streams.Stream_Element_Count) is record
-      Content : Ada.Streams.Stream_Element_Array (1 .. Size);
       Current : Ada.Streams.Stream_Element_Offset := 1;
       Last    : Ada.Streams.Stream_Element_Offset := 1;
       Next    : Node_Ptr;
+      Content : Ada.Streams.Stream_Element_Array (1 .. Size);
    end record;
 
    type Params_Stream_Type (Initial_Size : Ada.Streams.Stream_Element_Count) is
