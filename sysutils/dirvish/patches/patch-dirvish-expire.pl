$NetBSD: patch-dirvish-expire.pl,v 1.1 2024/06/27 17:40:34 abs Exp $

Taken from debian - Paul Slootman <paul@debian.org>
Subject: Fix for future reserved word warning

--- dirvish-expire.pl.orig	2024-06-20 09:09:32.049428903 +0000
+++ dirvish-expire.pl
@@ -140,7 +140,7 @@ if (!$$Options{quiet})
 		qw(VAULT:BRANCH IMAGE CREATED EXPIRED);
 }
 
-for $expire (sort(imsort @expires))
+for $expire (sort {imsort()} @expires)
 {
 	my ($created, $expired);
 	($created = $$expire{created}) =~ s/:\d\d$//;
