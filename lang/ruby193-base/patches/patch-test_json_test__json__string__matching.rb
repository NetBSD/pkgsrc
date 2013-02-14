$NetBSD: patch-test_json_test__json__string__matching.rb,v 1.1.2.2 2013/02/14 14:58:51 tron Exp $

Fix for CVE-2013-0269.

--- test/json/test_json_string_matching.rb.orig	2011-07-10 08:01:04.000000000 +0000
+++ test/json/test_json_string_matching.rb
@@ -27,14 +27,13 @@ class TestJsonStringMatching < Test::Uni
     t = TestTime.new
     t_json = [ t ].to_json
     assert_equal [ t ],
-      JSON.parse(t_json,
-        :match_string => { /\A\d{4}-\d{2}-\d{2}T\d{2}:\d{2}:\d{2}[+-]\d{4}\Z/ => TestTime })
+      JSON.parse(t_json, :create_additions => true,
+        :match_string => { /\A\d{4}-\d{2}-\d{2}T\d{2}:\d{2}:\d{2}[+-]\d{4}\z/ => TestTime })
     assert_equal [ t.strftime('%FT%T%z') ],
-      JSON.parse(t_json,
-        :match_string => { /\A\d{3}-\d{2}-\d{2}T\d{2}:\d{2}:\d{2}[+-]\d{4}\Z/ => TestTime })
+      JSON.parse(t_json, :create_additions => true,
+        :match_string => { /\A\d{3}-\d{2}-\d{2}T\d{2}:\d{2}:\d{2}[+-]\d{4}\z/ => TestTime })
     assert_equal [ t.strftime('%FT%T%z') ],
       JSON.parse(t_json,
-        :match_string => { /\A\d{4}-\d{2}-\d{2}T\d{2}:\d{2}:\d{2}[+-]\d{4}\Z/ => TestTime },
-        :create_additions => false)
+        :match_string => { /\A\d{4}-\d{2}-\d{2}T\d{2}:\d{2}:\d{2}[+-]\d{4}\z/ => TestTime })
   end
 end
