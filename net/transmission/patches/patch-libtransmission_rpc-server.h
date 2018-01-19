$NetBSD: patch-libtransmission_rpc-server.h,v 1.1.2.2 2018/01/19 21:33:24 spz Exp $

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

--- libtransmission/rpc-server.h.orig	2014-12-10 19:22:42.938222700 +0000
+++ libtransmission/rpc-server.h
@@ -49,6 +49,10 @@ void            tr_rpcSetWhitelist (tr_r
 
 const char*     tr_rpcGetWhitelist (const tr_rpc_server * server);
 
+void tr_rpcSetHostWhitelistEnabled(tr_rpc_server* server, bool isEnabled);
+
+void tr_rpcSetHostWhitelist(tr_rpc_server* server, char const* whitelist);
+
 void            tr_rpcSetPassword (tr_rpc_server * server,
                                    const char *    password);
 
