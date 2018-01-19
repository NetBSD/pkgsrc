$NetBSD: patch-libtransmission_session.c,v 1.1.2.2 2018/01/19 21:33:24 spz Exp $

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

--- libtransmission/session.c.orig	2016-01-09 18:02:58.743698889 +0000
+++ libtransmission/session.c
@@ -359,6 +359,8 @@ tr_sessionGetDefaultSettings (tr_variant
   tr_variantDictAddStr  (d, TR_KEY_rpc_username,                    "");
   tr_variantDictAddStr  (d, TR_KEY_rpc_whitelist,                   TR_DEFAULT_RPC_WHITELIST);
   tr_variantDictAddBool (d, TR_KEY_rpc_whitelist_enabled,           true);
+  tr_variantDictAddStr(d, TR_KEY_rpc_host_whitelist, TR_DEFAULT_RPC_HOST_WHITELIST);
+  tr_variantDictAddBool(d, TR_KEY_rpc_host_whitelist_enabled, true);
   tr_variantDictAddInt  (d, TR_KEY_rpc_port,                        atoi (TR_DEFAULT_RPC_PORT_STR));
   tr_variantDictAddStr  (d, TR_KEY_rpc_url,                         TR_DEFAULT_RPC_URL_STR);
   tr_variantDictAddBool (d, TR_KEY_scrape_paused_torrents_enabled,  true);
