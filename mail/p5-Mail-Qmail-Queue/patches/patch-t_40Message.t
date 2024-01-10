$NetBSD: patch-t_40Message.t,v 1.1 2024/01/10 16:45:17 schmonz Exp $

In tests, call the perl we're already using.

--- t/40Message.t.orig	2024-01-10 16:43:08.312532208 +0000
+++ t/40Message.t
@@ -32,7 +32,7 @@ is($msg->body,"That is a test message.\n
 is($msg->from,'sgifford@suspectclass.com-@[]');
 ok(eq_array($msg->to_ref,[qw(sgifford@suspectclass.com gifford@umich.edu GIFF@cpan.org)]));
 
-my $qq_res = $msg->send(QmailQueue => "perl -Iblib/lib t/30Send.qq @{[BODY_OUT]} @{[ENV_OUT]}");
+my $qq_res = $msg->send(QmailQueue => "$^X -Iblib/lib t/30Send.qq @{[BODY_OUT]} @{[ENV_OUT]}");
 is($qq_res,0);
 $qq_res == 0
     or die "qmail-queue send failed: status $qq_res";
