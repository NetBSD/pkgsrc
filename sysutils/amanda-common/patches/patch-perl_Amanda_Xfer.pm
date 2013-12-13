$NetBSD: patch-perl_Amanda_Xfer.pm,v 1.1 2013/12/13 16:27:34 schnoebe Exp $

Rather than try to conditionally eval in Amanda::XferServer based on the
value of Amanda::Constants::AMANDA_COMPONENTS, unconditionally attempt
to eval it in. The end result is the same.

--- perl/Amanda/Xfer.pm.orig	2012-02-21 11:39:17.000000000 +0000
+++ perl/Amanda/Xfer.pm
@@ -897,9 +897,6 @@ package Amanda::Xfer;
 # try to load Amanda::XferServer, which is server-only.  If it's not found, then
 # its classes just remain undefined.
 BEGIN {
-    use Amanda::Util;
-    if (Amanda::Util::built_with_component("server")) {
-	eval "use Amanda::XferServer;";
-    }
+      eval "use Amanda::XferServer;";
 }
 1;
