$NetBSD: patch-t_12.utf8.t,v 1.1 2018/07/28 15:52:34 schmonz Exp $

Fix "Wide character in print" warning when tests fail.
Add tests for a common 2-byte character.

--- t/12.utf8.t.orig	2013-11-15 18:26:06.000000000 +0000
+++ t/12.utf8.t
@@ -1,9 +1,27 @@
 use strict;
 use warnings;
 use utf8;
-use Test::More tests => 12;
+use Test::More tests => 16;
 use Text::Markdown::Discount;
 
+binmode Test::More->builder->$_, ':encoding(UTF-8)'
+	for qw(output failure_output todo_output);
+
+{
+    my $perl_string = '# ü';
+    my $html = Text::Markdown::Discount::markdown($perl_string);
+    like $html, qr!<h1>ü</h1>!;
+    ok utf8::is_utf8($html);
+}
+
+{
+    no utf8;
+    my $byte = '# ü';
+    my $html = Text::Markdown::Discount::markdown($byte);
+    like $html, qr!<h1>ü</h1>!;
+    ok !utf8::is_utf8($html);
+}
+
 {
     my $perl_string = '# あ';
     my $html = Text::Markdown::Discount::markdown($perl_string);
