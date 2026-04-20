$NetBSD: patch-libcody_server.cc,v 1.1 2026/04/20 03:49:24 js Exp $

--- libcody/server.cc.orig	2026-04-20 01:21:31.107113617 +0000
+++ libcody/server.cc
@@ -36,12 +36,12 @@ static RequestPair
   const requestTable[Detail::RC_HWM] =
   {
     // Same order as enum RequestCode
-    RequestPair {u8"HELLO", nullptr},
-    RequestPair {u8"MODULE-REPO", ModuleRepoRequest},
-    RequestPair {u8"MODULE-EXPORT", ModuleExportRequest},
-    RequestPair {u8"MODULE-IMPORT", ModuleImportRequest},
-    RequestPair {u8"MODULE-COMPILED", ModuleCompiledRequest},
-    RequestPair {u8"INCLUDE-TRANSLATE", IncludeTranslateRequest},
+    RequestPair {"HELLO", nullptr},
+    RequestPair {"MODULE-REPO", ModuleRepoRequest},
+    RequestPair {"MODULE-EXPORT", ModuleExportRequest},
+    RequestPair {"MODULE-IMPORT", ModuleImportRequest},
+    RequestPair {"MODULE-COMPILED", ModuleCompiledRequest},
+    RequestPair {"INCLUDE-TRANSLATE", IncludeTranslateRequest},
   };
 }
 
@@ -135,21 +135,21 @@ void Server::ProcessRequests (void)
 	  std::string msg;
 
 	  if (err > 0)
-	    msg = u8"error processing '";
+	    msg = "error processing '";
 	  else if (ix >= Detail::RC_HWM)
-	    msg = u8"unrecognized '";
+	    msg = "unrecognized '";
 	  else if (IsConnected () && ix == Detail::RC_CONNECT)
-	    msg = u8"already connected '";
+	    msg = "already connected '";
 	  else if (!IsConnected () && ix != Detail::RC_CONNECT)
-	    msg = u8"not connected '";
+	    msg = "not connected '";
 	  else
-	    msg = u8"malformed '";
+	    msg = "malformed '";
 
 	  read.LexedLine (msg);
-	  msg.append (u8"'");
+	  msg.append ("'");
 	  if (err > 0)
 	    {
-	      msg.append (u8" ");
+	      msg.append (" ");
 	      msg.append (strerror (err));
 	    }
 	  resolver->ErrorResponse (this, std::move (msg));
@@ -176,7 +176,7 @@ Resolver *ConnectRequest (Server *s, Res
     return nullptr;
 
   if (words.size () == 3)
-    words.emplace_back (u8"");
+    words.emplace_back ("");
   unsigned version = ParseUnsigned (words[1]);
   if (version == ~0u)
     return nullptr;
@@ -265,7 +265,7 @@ int IncludeTranslateRequest (Server *s,
 void Server::ErrorResponse (char const *error, size_t elen)
 {
   write.BeginLine ();
-  write.AppendWord (u8"ERROR");
+  write.AppendWord ("ERROR");
   write.AppendWord (error, true, elen);
   write.EndLine ();
 }
@@ -273,7 +273,7 @@ void Server::ErrorResponse (char const *
 void Server::OKResponse ()
 {
   write.BeginLine ();
-  write.AppendWord (u8"OK");
+  write.AppendWord ("OK");
   write.EndLine ();
 }
 
@@ -282,7 +282,7 @@ void Server::ConnectResponse (char const
   is_connected = true;
 
   write.BeginLine ();
-  write.AppendWord (u8"HELLO");
+  write.AppendWord ("HELLO");
   write.AppendInteger (Version);
   write.AppendWord (agent, true, alen);
   write.EndLine ();
@@ -291,7 +291,7 @@ void Server::ConnectResponse (char const
 void Server::PathnameResponse (char const *cmi, size_t clen)
 {
   write.BeginLine ();
-  write.AppendWord (u8"PATHNAME");
+  write.AppendWord ("PATHNAME");
   write.AppendWord (cmi, true, clen);
   write.EndLine ();
 }
@@ -299,8 +299,8 @@ void Server::PathnameResponse (char cons
 void Server::BoolResponse (bool truthiness)
 {
   write.BeginLine ();
-  write.AppendWord (u8"BOOL");
-  write.AppendWord (truthiness ? u8"TRUE" : u8"FALSE");
+  write.AppendWord ("BOOL");
+  write.AppendWord (truthiness ? "TRUE" : "FALSE");
   write.EndLine ();
 }
 
