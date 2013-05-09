$NetBSD: patch-src_torrent_http.h,v 1.1 2013/05/09 14:26:41 joerg Exp $

--- src/torrent/http.h.orig	2012-02-14 03:15:27.000000000 +0000
+++ src/torrent/http.h
@@ -40,7 +40,13 @@
 #include <string>
 #include <iosfwd>
 #include <list>
+#if __cplusplus >= 201103L
+#include <functional>
+using std::function;
+#else
 #include <tr1/functional>
+using std::tr1::function;
+#endif
 #include <torrent/common.h>
 
 namespace torrent {
@@ -51,9 +57,9 @@ namespace torrent {
 // Keep in mind that these objects get reused.
 class LIBTORRENT_EXPORT Http {
  public:
-  typedef std::tr1::function<void ()>                   slot_void;
-  typedef std::tr1::function<void (const std::string&)> slot_string;
-  typedef std::tr1::function<Http* (void)>              slot_http;
+  typedef function<void ()>                   slot_void;
+  typedef function<void (const std::string&)> slot_string;
+  typedef function<Http* (void)>              slot_http;
 
   typedef std::list<slot_void>   signal_void;
   typedef std::list<slot_string> signal_string;
