$NetBSD: patch-desktop_scripts_soffice.sh,v 1.7 2025/05/18 01:15:14 ryoon Exp $

1. chunk: Recent Firefox use newer version of NSS database format, cert9.db
   Use LibreOffice own cert8.db (older format).

--- desktop/scripts/soffice.sh.orig	2023-08-08 19:49:18.000000000 +0000
+++ desktop/scripts/soffice.sh
@@ -17,6 +17,10 @@
 #   the License at http://www.apache.org/licenses/LICENSE-2.0 .
 #
 
+# Do not depend on Mozilla profiles
+MOZILLA_CERTIFICATE_FOLDER=${HOME}/.config/libreoffice
+export MOZILLA_CERTIFICATE_FOLDER
+
 # use POSIX locale for well-defined tool output
 LO_SAVE_LC_ALL="$LC_ALL"
 LC_ALL=C
