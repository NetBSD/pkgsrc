$NetBSD: patch-shell_source_unix_misc_senddoc.sh,v 1.2 2021/04/10 13:13:47 ryoon Exp $

* Fix xdg-open path. PR pkg/56092
  https://bugs.documentfoundation.org/show_bug.cgi?id=108591

--- shell/source/unix/misc/senddoc.sh.orig	2021-03-24 16:28:10.000000000 +0000
+++ shell/source/unix/misc/senddoc.sh
@@ -393,6 +393,8 @@ case $(basename "$MAILER" | sed 's/-.*$/
             MAILER=/usr/bin/kde-open
         elif [ -x /usr/bin/xdg-open ] ; then
             MAILER=/usr/bin/xdg-open
+        elif command -v xdg-open >/dev/null 2>&1 ; then
+            MAILER="$(command -v xdg-open)"
         else
             echo "Unsupported mail client: $(basename $MAILER | sed 's/-.*^//')"
             exit 2
