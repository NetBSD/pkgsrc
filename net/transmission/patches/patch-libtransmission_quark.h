$NetBSD: patch-libtransmission_quark.h,v 1.1.2.2 2018/01/19 21:33:24 spz Exp $

Fix a weakness that allows remote code execution via the Transmission
RPC server using DNS rebinding:

https://bugs.chromium.org/p/project-zero/issues/detail?id=1447

Patch adapted from Tavis Ormandy's patch on the Transmission master
branch to the Transmission 2.92 release by Leo Famulari
<leo@famulari.name>:

https://github.com/transmission/transmission/pull/468/commits

From fe2d3c6e75088f3d9b6040ce06da3d530358bc2f Mon Sep 17 00:00:00 2001
From: Tavis Ormandy <taviso@google.com>
Date: Thu, 11 Jan 2018 10:00:41 -0800
Subject: [PATCH] mitigate dns rebinding attacks against daemon

---
 libtransmission/quark.c        |   2 +
 libtransmission/quark.h        |   2 +
 libtransmission/rpc-server.c   | 116 +++++++++++++++++++++++++++++++++++++----
 libtransmission/rpc-server.h   |   4 ++
 libtransmission/session.c      |   2 +
 libtransmission/transmission.h |   1 +
 libtransmission/web.c          |   3 ++
 7 files changed, 121 insertions(+), 9 deletions(-)

--- libtransmission/quark.h.orig	2015-06-28 19:23:49.613528096 +0000
+++ libtransmission/quark.h
@@ -291,6 +291,8 @@ enum
   TR_KEY_rpc_authentication_required,
   TR_KEY_rpc_bind_address,
   TR_KEY_rpc_enabled,
+  TR_KEY_rpc_host_whitelist,
+  TR_KEY_rpc_host_whitelist_enabled,
   TR_KEY_rpc_password,
   TR_KEY_rpc_port,
   TR_KEY_rpc_url,
