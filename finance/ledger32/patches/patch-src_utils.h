$NetBSD: patch-src_utils.h,v 1.1 2024/11/26 23:07:02 riastradh Exp $

Fix ctype abuse.
https://github.com/ledger/ledger/pull/2341

Fix build with boost>=1.86, which broke API compatibility.
https://github.com/ledger/ledger/issues/2378

--- src/utils.h.orig	2020-05-18 05:30:10.000000000 +0000
+++ src/utils.h
@@ -542,7 +542,7 @@ inline char * next_element(char * buf, b
 
 inline char peek_next_nonws(std::istream& in) {
   char c = static_cast<char>(in.peek());
-  while (in.good() && ! in.eof() && std::isspace(c)) {
+  while (in.good() && ! in.eof() && std::isspace(static_cast<unsigned char>(c))) {
     in.get(c);
     c = static_cast<char>(in.peek());
   }
@@ -607,14 +607,14 @@ inline char peek_next_nonws(std::istream
     *_p = '\0';                                         \
   }
 
-inline string to_hex(unsigned int * message_digest, const int len = 1)
+inline string to_hex(unsigned char * message_digest, const int len = 4)
 {
   std::ostringstream buf;
 
-  for(int i = 0; i < 5 ; i++) {
-    buf.width(8);
+  for(int i = 0; i < 20 ; i++) {
+    buf.width(2);
     buf.fill('0');
-    buf << std::hex << message_digest[i];
+    buf << std::hex << (int)message_digest[i];
     if (i + 1 >= len)
       break;                    // only output the first LEN dwords
   }
@@ -627,9 +627,9 @@ inline string sha1sum(const string& str)
 
   sha.process_bytes(str.c_str(), str.length());
 
-  unsigned int message_digest[5];
+  unsigned char message_digest[20];
   sha.get_digest(message_digest);
-  return to_hex(message_digest, 5);
+  return to_hex(message_digest, 20);
 }
 
 extern const string version;
