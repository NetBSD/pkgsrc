$NetBSD: patch-lib_Finance_Quote_VWD.pm,v 1.1 2011/02/26 05:39:45 obache Exp $

* http://rt.cpan.org/Public/Bug/Display.html?id=66041
 
--- lib/Finance/Quote/VWD.pm.orig	2009-10-05 17:39:57.000000000 +0000
+++ lib/Finance/Quote/VWD.pm
@@ -123,7 +123,10 @@ sub vwd
       next if not $content;
 
       # <h1> contains price, time, name, and symbol
-      my $head = $content->find("h1");
+      my $head = $content->look_down(
+        "_tag", "div",
+        "class", "wpHeadline"
+      );
       next if not $head;
 
       my $wpkurs = $head->look_down(
@@ -148,21 +151,24 @@ sub vwd
          $_->delete;
       }
 
-      if ($head->as_trimmed_text =~ /^(.*) \((.+)\)$/) {
-         $info{$fund, "name"} = $1;
-         $info{$fund, "symbol"} = $2;
+      my $wpsymbol = $content->look_down(
+         "_tag", "ul",
+         "class", "wpInfo"
+      );
+      if ($wpsymbol) {
+         my @li = $wpsymbol->find("li");
+         if ($li[4]->as_text =~ /WKN:(\w+)/) {
+            $info{$fund, "symbol"} = $1;
+         }
       }
 
       # <ul> contains currency as 3rd <li>
       my $wpinfo = $content->look_down(
-         "_tag", "ul",
-         "class", "wpInfo"
+         "_tag", "span",
+         "class", "whrg"
       );
       if ($wpinfo) {
-         my @li = $wpinfo->find("li");
-         if ($li[2]->as_text =~ /Währung:(\w+)/) {
-            $info{$fund, "currency"} = substr($1, 0, 3);
-         }
+         $info{$fund, "currency"} = substr($wpinfo->as_text, 0, 3);
       }
 
       # fund ok
