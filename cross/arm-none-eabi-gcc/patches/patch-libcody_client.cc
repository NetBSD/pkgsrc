$NetBSD: patch-libcody_client.cc,v 1.1 2026/04/20 03:49:24 js Exp $

--- libcody/client.cc.orig	2026-04-19 17:49:17.971655803 +0000
+++ libcody/client.cc
@@ -97,7 +97,7 @@ int Client::CommunicateWithServer ()
 
 static Packet CommunicationError (int err)
 {
-  std::string e {u8"communication error:"};
+  std::string e {"communication error:"};
   e.append (strerror (err));
 
   return Packet (Client::PC_ERROR, std::move (e));
@@ -110,33 +110,33 @@ Packet Client::ProcessResponse (std::vec
     {
       if (e == EINVAL)
 	{
-	  std::string msg (u8"malformed string '");
+	  std::string msg ("malformed string '");
 	  msg.append (words[0]);
-	  msg.append (u8"'");
+	  msg.append ("'");
 	  return Packet (Client::PC_ERROR, std::move (msg));
 	}
       else
-	return Packet (Client::PC_ERROR, u8"missing response");
+	return Packet (Client::PC_ERROR, "missing response");
     }
 
   Assert (!words.empty ());
-  if (words[0] == u8"ERROR")
+  if (words[0] == "ERROR")
     return Packet (Client::PC_ERROR,
-		   words.size () == 2 ? words[1]: u8"malformed error response");
+		   words.size () == 2 ? words[1]: "malformed error response");
 
   if (isLast && !read.IsAtEnd ())
     return Packet (Client::PC_ERROR,
-		   std::string (u8"unexpected extra response"));
+		   std::string ("unexpected extra response"));
 
   Assert (code < Detail::RC_HWM);
   Packet result (responseTable[code] (words));
   result.SetRequest (code);
   if (result.GetCode () == Client::PC_ERROR && result.GetString ().empty ())
     {
-      std::string msg {u8"malformed response '"};
+      std::string msg {"malformed response '"};
 
       read.LexedLine (msg);
-      msg.append (u8"'");
+      msg.append ("'");
       result.GetString () = std::move (msg);
     }
   else if (result.GetCode () == Client::PC_CONNECT)
@@ -199,7 +199,7 @@ Packet Client::Connect (char const *agen
 			  size_t alen, size_t ilen)
 {
   write.BeginLine ();
-  write.AppendWord (u8"HELLO");
+  write.AppendWord ("HELLO");
   write.AppendInteger (Version);
   write.AppendWord (agent, true, alen);
   write.AppendWord (ident, true, ilen);
@@ -211,14 +211,14 @@ Packet Client::Connect (char const *agen
 // HELLO $version $agent [$flags]
 Packet ConnectResponse (std::vector<std::string> &words)
 {
-  if (words[0] == u8"HELLO" && (words.size () == 3 || words.size () == 4))
+  if (words[0] == "HELLO" && (words.size () == 3 || words.size () == 4))
     {
       char *eptr;
       unsigned long val = strtoul (words[1].c_str (), &eptr, 10);
 
       unsigned version = unsigned (val);
       if (*eptr || version != val || version < Version)
-	return Packet (Client::PC_ERROR, u8"incompatible version");
+	return Packet (Client::PC_ERROR, "incompatible version");
       else
 	{
 	  unsigned flags = 0;
@@ -231,14 +231,14 @@ Packet ConnectResponse (std::vector<std:
 	}
     }
 
-  return Packet (Client::PC_ERROR, u8"");
+  return Packet (Client::PC_ERROR, "");
 }
 
 // MODULE-REPO
 Packet Client::ModuleRepo ()
 {
   write.BeginLine ();
-  write.AppendWord (u8"MODULE-REPO");
+  write.AppendWord ("MODULE-REPO");
   write.EndLine ();
 
   return MaybeRequest (Detail::RC_MODULE_REPO);
@@ -247,16 +247,16 @@ Packet Client::ModuleRepo ()
 // PATHNAME $dir | ERROR
 Packet PathnameResponse (std::vector<std::string> &words)
 {
-  if (words[0] == u8"PATHNAME" && words.size () == 2)
+  if (words[0] == "PATHNAME" && words.size () == 2)
     return Packet (Client::PC_PATHNAME, std::move (words[1]));
 
-  return Packet (Client::PC_ERROR, u8"");
+  return Packet (Client::PC_ERROR, "");
 }
 
 // OK or ERROR
 Packet OKResponse (std::vector<std::string> &words)
 {
-  if (words[0] == u8"OK")
+  if (words[0] == "OK")
     return Packet (Client::PC_OK);
   else
     return Packet (Client::PC_ERROR,
@@ -267,7 +267,7 @@ Packet OKResponse (std::vector<std::stri
 Packet Client::ModuleExport (char const *module, Flags flags, size_t mlen)
 {
   write.BeginLine ();
-  write.AppendWord (u8"MODULE-EXPORT");
+  write.AppendWord ("MODULE-EXPORT");
   write.AppendWord (module, true, mlen);
   if (flags != Flags::None)
     write.AppendInteger (unsigned (flags));
@@ -280,7 +280,7 @@ Packet Client::ModuleExport (char const
 Packet Client::ModuleImport (char const *module, Flags flags, size_t mlen)
 {
   write.BeginLine ();
-  write.AppendWord (u8"MODULE-IMPORT");
+  write.AppendWord ("MODULE-IMPORT");
   write.AppendWord (module, true, mlen);
   if (flags != Flags::None)
     write.AppendInteger (unsigned (flags));
@@ -293,7 +293,7 @@ Packet Client::ModuleImport (char const
 Packet Client::ModuleCompiled (char const *module, Flags flags, size_t mlen)
 {
   write.BeginLine ();
-  write.AppendWord (u8"MODULE-COMPILED");
+  write.AppendWord ("MODULE-COMPILED");
   write.AppendWord (module, true, mlen);
   if (flags != Flags::None)
     write.AppendInteger (unsigned (flags));
@@ -306,7 +306,7 @@ Packet Client::ModuleCompiled (char cons
 Packet Client::IncludeTranslate (char const *include, Flags flags, size_t ilen)
 {
   write.BeginLine ();
-  write.AppendWord (u8"INCLUDE-TRANSLATE");
+  write.AppendWord ("INCLUDE-TRANSLATE");
   write.AppendWord (include, true, ilen);
   if (flags != Flags::None)
     write.AppendInteger (unsigned (flags));
@@ -319,14 +319,14 @@ Packet Client::IncludeTranslate (char co
 // PATHNAME $cmifile
 Packet IncludeTranslateResponse (std::vector<std::string> &words)
 {
-  if (words[0] == u8"BOOL" && words.size () == 2)
+  if (words[0] == "BOOL" && words.size () == 2)
     {
-      if (words[1] == u8"FALSE")
+      if (words[1] == "FALSE")
 	return Packet (Client::PC_BOOL, 0);
-      else if (words[1] == u8"TRUE")
+      else if (words[1] == "TRUE")
 	return Packet (Client::PC_BOOL, 1);
       else
-	return Packet (Client::PC_ERROR, u8"");
+	return Packet (Client::PC_ERROR, "");
     }
   else
     return PathnameResponse (words);
