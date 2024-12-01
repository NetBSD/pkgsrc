$NetBSD: patch-dep_RtspServer_src_xop_rtsp.h,v 1.1 2024/12/01 13:49:47 gdt Exp $

Add NetBSD to BSD conditional.

\todo File upstream PR.

--- dep/RtspServer/src/xop/rtsp.h.orig	2024-01-14 21:21:34.574730494 +0000
+++ dep/RtspServer/src/xop/rtsp.h
@@ -51,7 +51,7 @@ public:
 		char ip[100] = { 0 };
 		char suffix[100] = { 0 };
 		uint16_t port = 0;
-#if defined(__linux) || defined(__linux__) || defined(__FreeBSD__) || defined(__OpenBSD__)
+#if defined(__linux) || defined(__linux__) || defined(__FreeBSD__)  || defined(__NetBSD__)|| defined(__OpenBSD__)
 		if (sscanf(url.c_str() + 7, "%[^:]:%hu/%s", ip, &port, suffix) == 3)
 #elif defined(WIN32) || defined(_WIN32)
 		if (sscanf_s(url.c_str() + 7, "%[^:]:%hu/%s", ip, 100, &port, suffix, 100) == 3)
@@ -59,7 +59,7 @@ public:
 		{
 			rtsp_url_info_.port = port;
 		}
-#if defined(__linux) || defined(__linux__) || defined(__FreeBSD__) || defined(__OpenBSD__)
+#if defined(__linux) || defined(__linux__) || defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__)
 		else if (sscanf(url.c_str() + 7, "%[^/]/%s", ip, suffix) == 2)
 #elif defined(WIN32) || defined(_WIN32)
 		else if (sscanf_s(url.c_str() + 7, "%[^/]/%s", ip, 100, suffix, 100) == 2)
