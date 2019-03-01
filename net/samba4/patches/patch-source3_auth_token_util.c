$NetBSD: patch-source3_auth_token_util.c,v 1.1 2019/03/01 20:03:24 roy Exp $

Taken from https://bugzilla.samba.org/show_bug.cgi?id=13697

From 1e8931dfc24a2576a3b1fe9115c4ccbfefbbd298 Mon Sep 17 00:00:00 2001
From: Stefan Metzmacher <metze@samba.org>
Date: Wed, 19 Dec 2018 09:38:33 +0100
Subject: [PATCH] s3:auth: ignore create_builtin_guests() failing without a
 valid idmap configuration

This happens on standalone servers, where winbindd is automatically
started by init scripts if it's installed. But it's not really
used and may not have a valid idmap configuration (
"idmap config * : range" has no default!)

BUG: https://bugzilla.samba.org/show_bug.cgi?id=13697

Signed-off-by: Stefan Metzmacher <metze@samba.org>
Reviewed-by: Alexander Bokovoy <ab@samba.org>
(cherry picked from commit 865538fabaea33741f5fa542dbc3f2e08308c2c1)
---
 source3/auth/token_util.c | 18 +++++++++++++++++-
 1 file changed, 17 insertions(+), 1 deletion(-)

diff --git a/source3/auth/token_util.c b/source3/auth/token_util.c
index f5b0e6944335..ee38d6c9645b 100644
--- source3/auth/token_util.c
+++ source3/auth/token_util.c
@@ -745,7 +745,23 @@ NTSTATUS finalize_local_nt_token(struct security_token *result,
 		status = create_builtin_guests(domain_sid);
 		unbecome_root();
 
-		if (NT_STATUS_EQUAL(status, NT_STATUS_PROTOCOL_UNREACHABLE)) {
+		/*
+		 * NT_STATUS_PROTOCOL_UNREACHABLE:
+		 * => winbindd is not running.
+		 *
+		 * NT_STATUS_ACCESS_DENIED:
+		 * => no idmap config at all
+		 * and wbint_AllocateGid()/winbind_allocate_gid()
+		 * failed.
+		 *
+		 * NT_STATUS_NO_SUCH_GROUP:
+		 * => no idmap config at all and
+		 * "tdbsam:map builtin = no" means
+		 * wbint_Sids2UnixIDs() fails.
+		 */
+		if (NT_STATUS_EQUAL(status, NT_STATUS_PROTOCOL_UNREACHABLE) ||
+		    NT_STATUS_EQUAL(status, NT_STATUS_ACCESS_DENIED) ||
+		    NT_STATUS_EQUAL(status, NT_STATUS_NO_SUCH_GROUP)) {
 			/*
 			 * Add BUILTIN\Guests directly to token.
 			 * But only if the token already indicates
