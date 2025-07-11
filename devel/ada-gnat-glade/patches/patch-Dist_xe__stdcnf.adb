$NetBSD: patch-Dist_xe__stdcnf.adb,v 1.1 2025/07/11 06:17:38 dkazankov Exp $

Fix some compilation warnings

--- Dist/xe_stdcnf.adb.orig	2007-11-26 14:06:30.000000000 +0200
+++ Dist/xe_stdcnf.adb
@@ -161,6 +161,8 @@
          Type_Sloc    => Null_Location,
          Type_Node    => Host_Function_Type_Node);
 
+      pragma Warnings (Off, "modified by call");
+
       Declare_Type_Component
         (Type_Node        => Host_Function_Type_Node,
          Component_Name   => Id ("partition_name"),
@@ -734,6 +736,8 @@
          Null_Location,
          Parameter_Node);
 
+      pragma Warnings (On, "modified by call");
+
    end Initialize;
 
 end XE_Stdcnf;
