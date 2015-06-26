$NetBSD: patch-testprogs_blackbox_dbcheck-oldrelease.sh,v 1.2 2015/06/26 16:09:49 jperkin Exp $

ERROR: [check-portability.awk] 

--- testprogs/blackbox/dbcheck-oldrelease.sh.orig	2014-10-01 09:16:22.000000000 +0000
+++ testprogs/blackbox/dbcheck-oldrelease.sh
@@ -178,19 +178,19 @@ dbcheck_clean2() {
 }
 
 referenceprovision() {
-    if [ x$RELEASE == x"release-4-0-0" ]; then
+    if [ x$RELEASE = x"release-4-0-0" ]; then
         $PYTHON $BINDIR/samba-tool domain provision --server-role="dc" --domain=SAMBA --host-name=ares --realm=${RELEASE}.samba.corp --targetdir=$PREFIX_ABS/${RELEASE}_reference --use-ntvfs --host-ip=127.0.0.1 --host-ip6=::1
     fi
 }
 
 ldapcmp() {
-    if [ x$RELEASE == x"release-4-0-0" ]; then
+    if [ x$RELEASE = x"release-4-0-0" ]; then
          $PYTHON $BINDIR/samba-tool ldapcmp tdb://$PREFIX_ABS/${RELEASE}_reference/private/sam.ldb tdb://$PREFIX_ABS/${RELEASE}/private/sam.ldb --two --skip-missing-dn --filter=dnsRecord
     fi
 }
 
 ldapcmp_sd() {
-    if [ x$RELEASE == x"release-4-0-0" ]; then
+    if [ x$RELEASE = x"release-4-0-0" ]; then
         $PYTHON $BINDIR/samba-tool ldapcmp tdb://$PREFIX_ABS/${RELEASE}_reference/private/sam.ldb tdb://$PREFIX_ABS/${RELEASE}/private/sam.ldb --two --sd --skip-missing-dn
     fi
 }
