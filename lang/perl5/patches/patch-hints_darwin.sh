$NetBSD: patch-hints_darwin.sh,v 1.1 2011/08/05 13:12:18 ryoon Exp $

Patch from http://perl5.git.perl.org/perl.git/commitdiff/60a655a1ee05c577268377c1135ffabc34dbff43

--- /usr/tmp/lang/perl5/work/perl-5.12.2/hints/darwin.sh.orig	2010-09-05 15:14:33.000000000 +0000
+++ /usr/tmp/lang/perl5/work/perl-5.12.2/hints/darwin.sh
@@ -68,8 +68,10 @@ esac
 # Since we can build fat, the archname doesn't need the processor type
 archname='darwin';
 
-# nm works.
-usenm='true';
+# nm isn't known to work after Snow Leopard and XCode 4; testing with OS X 10.5
+# and Xcode 3 shows a working nm, but pretending it doesn't work produces no
+# problems.
+usenm='false';
 
 case "$optimize" in
 '')
