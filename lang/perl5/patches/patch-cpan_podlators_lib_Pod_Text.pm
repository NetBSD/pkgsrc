$NetBSD: patch-cpan_podlators_lib_Pod_Text.pm,v 1.1 2026/09/19 19:18:02 wiz Exp $

From 70510174f69eb54aa6d617bde4e1402cd9b7c61f Mon Sep 17 00:00:00 2001
From: Russ Allbery <rra@cpan.org>
Date: Sat, 29 Aug 2026 10:29:37 -0700
Subject: [PATCH] Handle pathological margins in Pod::Text

If the margin equals or exceeds the output width, Pod::Text and its
subclasses could hang forever in the wrapping regular expression,
since it would successfully match zero characters. Catch this case,
report an error, and force the margin to zero.

--- cpan/podlators/lib/Pod/Text.pm.orig	2026-05-14 00:58:29.000000000 +0000
+++ cpan/podlators/lib/Pod/Text.pm
@@ -248,6 +248,17 @@ sub wrap {
     my $output = '';
     my $spaces = ' ' x $$self{MARGIN};
     my $width = $$self{opt_width} - $$self{MARGIN};
+
+    # Pathological margins make wrapping impossible.  In this case, complain
+    # to the user and reset the margin to 0.
+    if ($width <= 0) {
+        my $error = 'Margin is wider than the output width';
+        $self->whine($self->line_count(), $error);
+        $spaces = q{};
+        $width = $self->{opt_width};
+    }
+
+    # Perform the wrapping.
     while (length > $width) {
         if (s/^([^\n]{0,$width})[ \t\n]+// || s/^([^\n]{$width})//) {
             $output .= $spaces . $1 . "\n";
@@ -1162,6 +1173,13 @@ character long or an even number (greater than one) ch
 (F) The quote specification given (the C<quotes> option to the
 constructor) was invalid.  A quote specification must be either one
 character long or an even number (greater than one) characters long.
+
+=item Margin is wider than the output width
+
+(W) The requested margin width, determined from the sum of indentations
+requested by C<=over> and the baseline indentation for text, is equal to or
+wider than the desired output width specified with C<width>.  The text will
+be formatted as if the margin was set to zero.
 
 =item POD document had syntax errors
 
