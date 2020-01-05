$NetBSD: patch-third__party_rust_url_src_form__urlencoded.rs,v 1.1 2020/01/05 02:20:08 ryoon Exp $

* Fix build with rust-1.40.0
  From: https://docs.freebsd.org/cgi/getmsg.cgi?fetch=1073761+0+/usr/local/www/mailindex/archive/2019/svn-ports-head/20191222.svn-ports-head

--- third_party/rust/url/src/form_urlencoded.rs.orig	2019-09-01 13:10:20.000000000 +0000
+++ third_party/rust/url/src/form_urlencoded.rs
@@ -257,8 +257,16 @@ impl<'a> Target for &'a mut String {
 // * `Serializer` keeps its target in a private field
 // * Unlike in other `Target` impls, `UrlQuery::finished` does not return `Self`.
 impl<'a> Target for ::UrlQuery<'a> {
-    fn as_mut_string(&mut self) -> &mut String { &mut self.url.serialization }
-    fn finish(self) -> &'a mut ::Url { self.url }
+    fn as_mut_string(&mut self) -> &mut String {
+        &mut self.url.as_mut().unwrap().serialization
+    }
+
+    fn finish(mut self) -> &'a mut ::Url {
+        let url = self.url.take().unwrap();
+        url.restore_already_parsed_fragment(self.fragment.take());
+        url
+    }
+
     type Finished = &'a mut ::Url;
 }
 
