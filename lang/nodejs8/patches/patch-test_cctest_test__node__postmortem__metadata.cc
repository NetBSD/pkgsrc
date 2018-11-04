$NetBSD: patch-test_cctest_test__node__postmortem__metadata.cc,v 1.1 2018/11/04 00:41:22 ryoon Exp $

--- test/cctest/test_node_postmortem_metadata.cc.orig	2018-09-10 18:47:04.000000000 +0000
+++ test/cctest/test_node_postmortem_metadata.cc
@@ -19,9 +19,9 @@ extern uintptr_t
 extern uintptr_t
     nodedbg_offset_Environment__req_wrap_queue___Environment_ReqWrapQueue;
 extern uintptr_t nodedbg_offset_ExternalString__data__uintptr_t;
-extern uintptr_t nodedbg_offset_ListNode_ReqWrap__next___uintptr_t;
+extern uintptr_t nodedbg_offset_ListNode_ReqWrap__next___uintptr_t = 0;
 extern uintptr_t nodedbg_offset_ReqWrap__req_wrap_queue___ListNode_ReqWrapQueue;
-extern uintptr_t nodedbg_offset_ListNode_HandleWrap__next___uintptr_t;
+extern uintptr_t nodedbg_offset_ListNode_HandleWrap__next___uintptr_t = 0;
 extern uintptr_t
     nodedbg_offset_Environment_ReqWrapQueue__head___ListNode_ReqWrapQueue;
 extern uintptr_t
