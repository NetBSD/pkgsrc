$NetBSD: patch-cpan_podlators_lib_Pod_Text_Color.pm,v 1.1 2026/09/19 19:18:02 wiz Exp $

From 70510174f69eb54aa6d617bde4e1402cd9b7c61f Mon Sep 17 00:00:00 2001
From: Russ Allbery <rra@cpan.org>
Date: Sat, 29 Aug 2026 10:29:37 -0700
Subject: [PATCH] Handle pathological margins in Pod::Text

If the margin equals or exceeds the output width, Pod::Text and its
subclasses could hang forever in the wrapping regular expression,
since it would successfully match zero characters. Catch this case,
report an error, and force the margin to zero.

--- cpan/podlators/lib/Pod/Text/Color.pm.orig	2026-05-14 00:58:29.000000000 +0000
+++ cpan/podlators/lib/Pod/Text/Color.pm
@@ -191,7 +191,7 @@ Russ Allbery <rra@cpan.org>.
 
 =head1 COPYRIGHT AND LICENSE
 
-Copyright 1999, 2001, 2004, 2006, 2008, 2009, 2018-2019, 2022, 2024 Russ
+Copyright 1999, 2001, 2004, 2006, 2008, 2009, 2018-2019, 2022, 2024, 2026 Russ
 Allbery <rra@cpan.org>
 
 This program is free software; you may redistribute it and/or modify it
