$NetBSD: patch-atf-c_detail_process.c,v 1.1 2026/09/02 15:35:03 adam Exp $

Fix build: si_code is a macro on NetBSD.

--- atf-c/detail/process.c.orig	2026-09-02 15:28:37.877635416 +0000
+++ atf-c/detail/process.c
@@ -218,8 +218,8 @@ atf_process_status_signaled(const atf_process_status_t
 bool
 atf_process_status_signaled(const atf_process_status_t *s)
 {
-    int si_code = s->m_info.si_code;
-    return si_code == CLD_KILLED || si_code == CLD_DUMPED;
+    int code = s->m_info.si_code;
+    return code == CLD_KILLED || code == CLD_DUMPED;
 }
 
 int
