$NetBSD: patch-lib_Mail_SpamAssassin_PerMsgStatus.pm,v 1.1 2013/12/04 15:14:19 jperkin Exp $

Part of backport of bug#6937

--- lib/Mail/SpamAssassin/PerMsgStatus.pm.orig	2011-06-06 23:59:17.000000000 +0000
+++ lib/Mail/SpamAssassin/PerMsgStatus.pm
@@ -420,8 +420,8 @@ sub _get_autolearn_points {
       }
     }
 
-    # ignore tests with 0 score in this scoreset
-    next if ($scores->{$test} == 0);
+    # ignore tests with 0 score (or undefined) in this scoreset
+    next if !$scores->{$test};
 
     # Go ahead and add points to the proper locations
     if (!$self->{conf}->maybe_header_only ($test)) {
@@ -1252,13 +1252,12 @@ sub _get_tag {
               my $arg = (shift || ",");
               my $line = '';
               foreach my $test (sort @{$self->{test_names_hit}}) {
-                if (!$line) {
-                  $line .= $test . "=" . $self->{conf}->{scores}->{$test};
-                } else {
-                  $line .= $arg . $test . "=" . $self->{conf}->{scores}->{$test};
-                }
+                my $score = $self->{conf}->{scores}->{$test};
+                $score = '0'  if !defined $score;
+                $line .= $arg  if $line ne '';
+                $line .= $test . "=" . $score;
               }
-              $line ? $line : 'none';
+              $line ne '' ? $line : 'none';
             },
 
             PREVIEW => sub { $self->get_content_preview() },
