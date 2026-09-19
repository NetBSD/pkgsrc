$NetBSD: patch-cpan_podlators_lib_Pod_Text_Overstrike.pm,v 1.1 2026/09/19 19:18:02 wiz Exp $

From 70510174f69eb54aa6d617bde4e1402cd9b7c61f Mon Sep 17 00:00:00 2001
From: Russ Allbery <rra@cpan.org>
Date: Sat, 29 Aug 2026 10:29:37 -0700
Subject: [PATCH] Handle pathological margins in Pod::Text

If the margin equals or exceeds the output width, Pod::Text and its
subclasses could hang forever in the wrapping regular expression,
since it would successfully match zero characters. Catch this case,
report an error, and force the margin to zero.

--- cpan/podlators/lib/Pod/Text/Overstrike.pm.orig	2026-05-14 00:58:29.000000000 +0000
+++ cpan/podlators/lib/Pod/Text/Overstrike.pm
@@ -103,6 +103,16 @@ sub wrap {
     my $output = '';
     my $spaces = ' ' x $$self{MARGIN};
     my $width = $$self{opt_width} - $$self{MARGIN};
+
+    # Pathological margins make wrapping impossible. In this case, complain to
+    # the user and reset the margin to 0.
+    if ($width <= 0) {
+        my $error = 'Margin is wider than the output width';
+        $self->whine($self->line_count(), $error);
+        $spaces = q{};
+        $width = $self->{opt_width};
+    }
+
     while (length > $width) {
         # This regex represents a single character, that's possibly underlined
         # or in bold (in which case, it's three characters; the character, a
@@ -198,7 +208,7 @@ Copyright 2000 Joe Smith <Joe.Smith@inwap.com>
 
 Copyright 2000 Joe Smith <Joe.Smith@inwap.com>
 
-Copyright 2001, 2004, 2008, 2014, 2018-2019, 2022, 2024 Russ Allbery
+Copyright 2001, 2004, 2008, 2014, 2018-2019, 2022, 2024, 2026 Russ Allbery
 <rra@cpan.org>
 
 This program is free software; you may redistribute it and/or modify it
