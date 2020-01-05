$NetBSD: patch-third__party_rust_url_src_lib.rs,v 1.1 2020/01/05 02:20:08 ryoon Exp $

* Fix build with rust-1.40.0
  From: https://docs.freebsd.org/cgi/getmsg.cgi?fetch=1073761+0+/usr/local/www/mailindex/archive/2019/svn-ports-head/20191222.svn-ports-head

--- third_party/rust/url/src/lib.rs.orig	2019-09-01 13:10:20.000000000 +0000
+++ third_party/rust/url/src/lib.rs
@@ -1304,7 +1304,7 @@ impl Url {
             self.serialization.push('?');
         }
 
-        let query = UrlQuery { url: self, fragment: fragment };
+        let query = UrlQuery { url: Some(self), fragment: fragment };
         form_urlencoded::Serializer::for_suffix(query, query_start + "?".len())
     }
 
@@ -2373,13 +2373,15 @@ fn io_error<T>(reason: &str) -> io::Resu
 /// Implementation detail of `Url::query_pairs_mut`. Typically not used directly.
 #[derive(Debug)]
 pub struct UrlQuery<'a> {
-    url: &'a mut Url,
+    url: Option<&'a mut Url>,
     fragment: Option<String>,
 }
 
 impl<'a> Drop for UrlQuery<'a> {
     fn drop(&mut self) {
-        self.url.restore_already_parsed_fragment(self.fragment.take())
+        if let Some(url) = self.url.take() {
+            url.restore_already_parsed_fragment(self.fragment.take())
+        }
     }
 }
 
