$NetBSD: patch-structs.h,v 1.1 2019/07/28 10:26:43 nia Exp $

64bit Compatible Saves
https://patch-diff.githubusercontent.com/raw/diasurgical/devilutionX/pull/162.patch

--- structs.h.orig	2019-05-19 17:06:45.000000000 +0000
+++ structs.h
@@ -655,6 +655,7 @@ typedef struct ObjDataStruct {
 	BOOL oTrapFlag;
 } ObjDataStruct;
 
+#pragma pack(push, 4)
 typedef struct ObjectStruct {
 	int _otype;
 	int _ox;
@@ -687,11 +688,13 @@ typedef struct ObjectStruct {
 	int _oVar7;
 	int _oVar8;
 } ObjectStruct;
+#pragma pack(pop)
 
 //////////////////////////////////////////////////
 // portal
 //////////////////////////////////////////////////
 
+#pragma pack(push, 4)
 typedef struct PortalStruct {
 	BOOL open;
 	int x;
@@ -700,6 +703,7 @@ typedef struct PortalStruct {
 	int ltype;
 	BOOL setlvl;
 } PortalStruct;
+#pragma pack(pop)
 
 //////////////////////////////////////////////////
 // msg
@@ -966,6 +970,7 @@ typedef struct TBuffer {
 // quests
 //////////////////////////////////////////////////
 
+#pragma pack(push, 4)
 typedef struct QuestStruct {
 	unsigned char _qlevel;
 	unsigned char _qtype;
@@ -980,6 +985,7 @@ typedef struct QuestStruct {
 	unsigned char _qvar2;
 	int _qlog;
 } QuestStruct;
+#pragma pack(pop)
 
 typedef struct QuestData {
 	unsigned char _qdlvl;
