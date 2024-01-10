$NetBSD: patch-t_30Send.t,v 1.1 2024/01/10 16:45:17 schmonz Exp $

In tests, call the perl we're already using.

--- t/30Send.t.orig	2024-01-10 16:43:08.307574424 +0000
+++ t/30Send.t
@@ -13,7 +13,7 @@ use constant ENV_FN => 't/30Send.env';
 
 unlink(BODY_FN,ENV_FN);
 
-my $qq_send = Mail::Qmail::Queue::Send->new(QmailQueue => "perl -Iblib/lib t/30Send.qq @{[BODY_FN]} @{[ENV_FN]}")
+my $qq_send = Mail::Qmail::Queue::Send->new(QmailQueue => "$^X -Iblib/lib t/30Send.qq @{[BODY_FN]} @{[ENV_FN]}")
     or die "Couldn't create qmail-queue sender: $!\n";
 $qq_send->body("Test message\n")
     or die "Couldn't write body: $!\n";
