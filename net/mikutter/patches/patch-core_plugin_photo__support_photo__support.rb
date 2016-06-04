$NetBSD: patch-core_plugin_photo__support_photo__support.rb,v 1.3 2016/06/04 02:28:25 tsutsui Exp $

- temporary workaround to skip totorijp gems (sorry, @toshi_a)

--- core/plugin/photo_support/photo_support.rb.orig	2016-05-28 16:42:44.000000000 +0000
+++ core/plugin/photo_support/photo_support.rb
@@ -1,7 +1,7 @@
 # coding: utf-8
 require 'nokogiri'
 require 'httpclient'
-require 'totoridipjp'
+#require 'totoridipjp'
 
 module Plugin::PhotoSupport
   INSTAGRAM_PATTERN = %r{\Ahttps?://(?:instagr\.am|(?:www\.)?instagram\.com)/p/([a-zA-Z0-9_\-]+)/}
@@ -181,9 +181,14 @@ Plugin.create :photo_support do
 
   # totori.dip.jp
   defimageopener('totori.dip.jp', %r#\Ahttp://totori\.dip\.jp/?\Z#) do |display_url|
-    iwashi = Totoridipjp.イワシがいっぱいだあ…ちょっとだけもらっていこうかな
-    if iwashi.url
-      open(iwashi.url) end
+#    iwashi = Totoridipjp.イワシがいっぱいだあ…ちょっとだけもらっていこうかな
+#    if iwashi.url
+#      open(iwashi.url) end
+    connection = HTTPClient.new
+    page = connection.get_content(display_url)
+    next nil if page.empty?
+    doc = Nokogiri::HTML(page)
+    open(doc.css('meta[property="og:image"]').first.attribute('content'))
   end
 
   # 600eur.gochiusa.net
