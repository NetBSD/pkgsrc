$NetBSD: patch-lib_Net_DNS_Fingerprint.pm,v 1.1 2013/07/31 10:23:17 he Exp $

Change NS_NOTIFY_OP to just NOTIFY, to allow this to work
with p5-Net-DNS 0.69.

--- lib/Net/DNS/Fingerprint.pm.orig	2012-10-19 08:54:24.000000000 +0000
+++ lib/Net/DNS/Fingerprint.pm
@@ -52,7 +52,7 @@ my $ignore_recurse = 0;
 my @qy = (
     "0,QUERY,0,0,0,0,0,0,NOERROR,0,0,0,0",          #qy0
     "0,QUERY,0,0,0,1,0,1,NOERROR,0,0,0,0",          #qy1
-    "0,NS_NOTIFY_OP,0,1,1,0,1,1,NOTIMP,0,0,0,0",    #qy2
+    "0,NOTIFY,0,1,1,0,1,1,NOTIMP,0,0,0,0",    #qy2
     "0,IQUERY,0,0,0,1,1,1,NOERROR,0,0,0,0",         #qy3
     "0,QUERY,0,0,1,0,0,0,NOERROR,0,0,0,0",          #qy4
     "0,QUERY,0,0,1,0,0,0,NOERROR,0,0,0,0",          #qy5
@@ -85,15 +85,15 @@ my @iq = (
     "1,QUERY,0,0,0,0,0,0,NXDOMAIN,1,0,0,0",           #iq1
     "1,QUERY,0,0,0,0,0,0,NOERROR,1,0,0,0",            #iq2
     "1,QUERY,0,0,0,1,0,0,NOERROR,.+,.+,.+,.+",        #iq3
-    "1,NS_NOTIFY_OP,0,0,1,1,0,1,FORMERR,1,0,0,0",     #iq4
-    "1,NS_NOTIFY_OP,0,0,1,1,0,0,FORMERR,1,0,0,0",     #iq5
-    "1,NS_NOTIFY_OP,0,0,1,1,0,0,REFUSED,1,0,0,0",     #iq6
-    "0,NS_NOTIFY_OP,0,1,1,0,1,1,NOTIMP,1,0,0,0",      #iq7
+    "1,NOTIFY,0,0,1,1,0,1,FORMERR,1,0,0,0",     #iq4
+    "1,NOTIFY,0,0,1,1,0,0,FORMERR,1,0,0,0",     #iq5
+    "1,NOTIFY,0,0,1,1,0,0,REFUSED,1,0,0,0",     #iq6
+    "0,NOTIFY,0,1,1,0,1,1,NOTIMP,1,0,0,0",      #iq7
     "1,IQUERY,0,0,0,1,0,0,NOTIMP,1,0,0,0",            #iq8
     "0,IQUERY,0,0,0,1,1,1,NOERROR,1,0,0,0",           #iq9
     "1,QUERY,0,0,1,0,0,0,NOTIMP,1,0,0,0",             #iq10
     "0,QUERY,0,0,1,0,0,0,NOERROR,1,0,0,0",            #iq11
-    "1,NS_NOTIFY_OP,0,0,1,1,0,0,SERVFAIL,1,0,0,0",    #iq12
+    "1,NOTIFY,0,0,1,1,0,0,SERVFAIL,1,0,0,0",    #iq12
     "1,IQUERY,0,0,1,1,0,0,SERVFAIL,1,0,0,0",          #iq13
     "1,IQUERY,0,0,1,1,0,0,NOTIMP,0,0,0,0",            #iq14
     "1,QUERY,0,0,0,1,0,0,NOTIMP,.+,.+,.+,.+",         #iq15
@@ -406,7 +406,7 @@ my @ruleset = (
 
 my @qy_old = (
     "0,IQUERY,0,0,1,0,0,0,NOERROR,0,0,0,0",
-    "0,NS_NOTIFY_OP,0,0,0,0,0,0,NOERROR,0,0,0,0",
+    "0,NOTIFY,0,0,0,0,0,0,NOERROR,0,0,0,0",
     "0,QUERY,0,0,0,0,0,0,NOERROR,0,0,0,0",
     "0,IQUERY,0,0,0,0,1,1,NOERROR,0,0,0,0",
     "0,QUERY,0,0,0,0,0,0,NOTIMP,0,0,0,0",
@@ -430,20 +430,20 @@ my @iq_old = (
     "1,QUERY,1,0,1,0,0,0,NOTIMP,1,0,0,0",
     "1,QUERY,0,0,0,0,0,0,NOTIMP,0,0,0,0",
     "1,IQUERY,0,0,1,1,0,0,FORMERR,1,0,0,0",    # iq_old10
-    "1,NS_NOTIFY_OP,0,0,0,0,0,0,FORMERR,1,0,0,0",
-    "1,NS_NOTIFY_OP,0,0,0,0,0,0,NOTIMP,0,0,0,0",
-    "1,NS_NOTIFY_OP,0,0,0,0,0,0,NOTIMP,1,0,0,0",
-    "1,NS_NOTIFY_OP,0,0,0,0,0,0,NXDOMAIN,1,0,0,0",
-    "1,NS_NOTIFY_OP,0,0,0,0,0,0,REFUSED,1,0,0,0",
-    "1,NS_NOTIFY_OP,0,0,0,0,0,0,SERVFAIL,1,0,0,0",
-    "1,NS_NOTIFY_OP,0,0,0,1,0,0,FORMERR,1,0,0,0",
-    "1,NS_NOTIFY_OP,0,0,0,1,0,0,NOTIMP,0,0,0,0",
-    "1,NS_NOTIFY_OP,0,0,0,1,0,0,NOTIMP,1,0,0,0",
-    "1,NS_NOTIFY_OP,0,0,0,1,0,0,REFUSED,1,0,0,0",    # iq_old20
-    "1,NS_NOTIFY_OP,0,0,0,1,0,0,SERVFAIL,1,0,0,0",
-    "1,NS_NOTIFY_OP,1,0,0,0,0,0,NOTIMP,1,0,0,0",
+    "1,NOTIFY,0,0,0,0,0,0,FORMERR,1,0,0,0",
+    "1,NOTIFY,0,0,0,0,0,0,NOTIMP,0,0,0,0",
+    "1,NOTIFY,0,0,0,0,0,0,NOTIMP,1,0,0,0",
+    "1,NOTIFY,0,0,0,0,0,0,NXDOMAIN,1,0,0,0",
+    "1,NOTIFY,0,0,0,0,0,0,REFUSED,1,0,0,0",
+    "1,NOTIFY,0,0,0,0,0,0,SERVFAIL,1,0,0,0",
+    "1,NOTIFY,0,0,0,1,0,0,FORMERR,1,0,0,0",
+    "1,NOTIFY,0,0,0,1,0,0,NOTIMP,0,0,0,0",
+    "1,NOTIFY,0,0,0,1,0,0,NOTIMP,1,0,0,0",
+    "1,NOTIFY,0,0,0,1,0,0,REFUSED,1,0,0,0",    # iq_old20
+    "1,NOTIFY,0,0,0,1,0,0,SERVFAIL,1,0,0,0",
+    "1,NOTIFY,1,0,0,0,0,0,NOTIMP,1,0,0,0",
     "1,QUERY,1,0,0,0,0,0,NOTIMP,1,0,0,0",
-    "1,NS_NOTIFY_OP,1,0,0,0,0,0,SERVFAIL,1,0,0,0",
+    "1,NOTIFY,1,0,0,0,0,0,SERVFAIL,1,0,0,0",
     "1,IQUERY,0,0,0,0,1,1,NOTIMP,0,0,0,0",
     "1,IQUERY,0,0,0,0,0,0,NOTIMP,0,0,0,0",
     "1,IQUERY,0,0,1,1,1,1,FORMERR,0,0,0,0",
