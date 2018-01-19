$NetBSD: patch-libtransmission_rpc-server.c,v 1.1.2.2 2018/01/19 21:33:24 spz Exp $

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

--- libtransmission/rpc-server.c.orig	2016-01-09 18:02:58.740698836 +0000
+++ libtransmission/rpc-server.c
@@ -52,6 +52,7 @@ struct tr_rpc_server
     bool               isEnabled;
     bool               isPasswordEnabled;
     bool               isWhitelistEnabled;
+    bool               isHostWhitelistEnabled;
     tr_port            port;
     char             * url;
     struct in_addr     bindAddress;
@@ -63,6 +64,7 @@ struct tr_rpc_server
     char             * password;
     char             * whitelistStr;
     tr_list          * whitelist;
+    tr_list          * hostWhitelist;
 
     char             * sessionId;
     time_t             sessionIdExpiresAt;
@@ -588,6 +590,49 @@ isAddressAllowed (const tr_rpc_server * 
   return false;
 }
 
+static bool isHostnameAllowed(tr_rpc_server const* server, struct evhttp_request* req)
+{
+    /* If password auth is enabled, any hostname is permitted. */
+    if (server->isPasswordEnabled)
+    {
+        return true;
+    }
+
+    char const* const host = evhttp_find_header(req->input_headers, "Host");
+
+    // If whitelist is disabled, no restrictions.
+    if (!server->isHostWhitelistEnabled)
+        return true;
+
+    /* No host header, invalid request. */
+    if (host == NULL)
+    {
+        return false;
+    }
+
+    /* Host header might include the port. */
+    char* const hostname = tr_strndup(host, strcspn(host, ":"));
+
+    /* localhost or ipaddress is always acceptable. */
+    if (strcmp(hostname, "localhost") == 0 || strcmp(hostname, "localhost.") == 0 || tr_addressIsIP(hostname))
+    {
+        tr_free(hostname);
+        return true;
+    }
+
+    /* Otherwise, hostname must be whitelisted. */
+    for (tr_list* l = server->hostWhitelist; l != NULL; l = l->next) {
+        if (tr_wildmat(hostname, l->data))
+        {
+            tr_free(hostname);
+            return true;
+        }
+    }
+
+    tr_free(hostname);
+    return false;
+}
+
 static bool
 test_session_id (struct tr_rpc_server * server, struct evhttp_request * req)
 {
@@ -663,6 +708,23 @@ handle_request (struct evhttp_request * 
           handle_upload (req, server);
         }
 #ifdef REQUIRE_SESSION_ID
+        else if (!isHostnameAllowed(server, req))
+        {
+            char* tmp = tr_strdup_printf(
+                "<p>Transmission received your request, but the hostname was unrecognized.</p>"
+                "<p>To fix this, choose one of the following options:"
+                "<ul>"
+                "<li>Enable password authentication, then any hostname is allowed.</li>"
+                "<li>Add the hostname you want to use to the whitelist in settings.</li>"
+                "</ul></p>"
+                "<p>If you're editing settings.json, see the 'rpc-host-whitelist' and 'rpc-host-whitelist-enabled' entries.</p>"
+                "<p>This requirement has been added to help prevent "
+                "<a href=\"https://en.wikipedia.org/wiki/DNS_rebinding\">DNS Rebinding</a> "
+                "attacks.</p>");
+            send_simple_response(req, 421, tmp);
+            tr_free(tmp);
+        }
+
       else if (!test_session_id (server, req))
         {
           const char * sessionId = get_current_session_id (server);
@@ -674,7 +736,7 @@ handle_request (struct evhttp_request * 
             "<li> When you get this 409 error message, resend your request with the updated header"
             "</ol></p>"
             "<p>This requirement has been added to help prevent "
-            "<a href=\"http://en.wikipedia.org/wiki/Cross-site_request_forgery\">CSRF</a> "
+            "<a href=\"https://en.wikipedia.org/wiki/Cross-site_request_forgery\">CSRF</a> "
             "attacks.</p>"
             "<p><code>%s: %s</code></p>",
             TR_RPC_SESSION_ID_HEADER, sessionId);
@@ -875,19 +937,14 @@ tr_rpcGetUrl (const tr_rpc_server * serv
   return server->url ? server->url : "";
 }
 
-void
-tr_rpcSetWhitelist (tr_rpc_server * server, const char * whitelistStr)
+static void
+tr_rpcSetList (char const* whitelistStr, tr_list** list)
 {
   void * tmp;
   const char * walk;
 
-  /* keep the string */
-  tmp = server->whitelistStr;
-  server->whitelistStr = tr_strdup (whitelistStr);
-  tr_free (tmp);
-
   /* clear out the old whitelist entries */
-  while ((tmp = tr_list_pop_front (&server->whitelist)))
+  while ((tmp = tr_list_pop_front (list)) != NULL)
     tr_free (tmp);
 
   /* build the new whitelist entries */
@@ -896,7 +953,7 @@ tr_rpcSetWhitelist (tr_rpc_server * serv
       const char * delimiters = " ,;";
       const size_t len = strcspn (walk, delimiters);
       char * token = tr_strndup (walk, len);
-      tr_list_append (&server->whitelist, token);
+      tr_list_append (list, token);
       if (strcspn (token, "+-") < len)
         tr_logAddNamedInfo (MY_NAME, "Adding address to whitelist: %s (And it has a '+' or '-'!  Are you using an old ACL by mistake?)", token);
       else
@@ -909,6 +966,21 @@ tr_rpcSetWhitelist (tr_rpc_server * serv
     }
 }
 
+void tr_rpcSetHostWhitelist(tr_rpc_server* server, char const* whitelistStr)
+{
+    tr_rpcSetList(whitelistStr, &server->hostWhitelist);
+}
+
+void tr_rpcSetWhitelist(tr_rpc_server* server, char const* whitelistStr)
+{
+    /* keep the string */
+    char* const tmp = server->whitelistStr;
+    server->whitelistStr = tr_strdup(whitelistStr);
+    tr_free(tmp);
+
+    tr_rpcSetList(whitelistStr, &server->whitelist);
+}
+
 const char*
 tr_rpcGetWhitelist (const tr_rpc_server * server)
 {
@@ -930,6 +1002,11 @@ tr_rpcGetWhitelistEnabled (const tr_rpc_
   return server->isWhitelistEnabled;
 }
 
+void tr_rpcSetHostWhitelistEnabled(tr_rpc_server* server, bool isEnabled)
+{
+    server->isHostWhitelistEnabled = isEnabled;
+}
+
 /****
 *****  PASSWORD
 ****/
@@ -1063,6 +1140,28 @@ tr_rpcInit (tr_session  * session, tr_va
   else
     tr_rpcSetWhitelistEnabled (s, boolVal);
 
+  key = TR_KEY_rpc_host_whitelist_enabled;
+
+  if (!tr_variantDictFindBool(settings, key, &boolVal))
+  {
+      missing_settings_key(key);
+  }
+  else
+  {
+      tr_rpcSetHostWhitelistEnabled(s, boolVal);
+  }
+
+  key = TR_KEY_rpc_host_whitelist;
+
+  if (!tr_variantDictFindStr(settings, key, &str, NULL) && str != NULL)
+  {
+      missing_settings_key(key);
+  }
+  else
+  {
+      tr_rpcSetHostWhitelist(s, str);
+  }
+
   key = TR_KEY_rpc_authentication_required;
   if (!tr_variantDictFindBool (settings, key, &boolVal))
     missing_settings_key (key);
