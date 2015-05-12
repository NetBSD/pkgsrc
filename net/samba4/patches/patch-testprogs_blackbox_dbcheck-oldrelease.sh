$NetBSD: patch-testprogs_blackbox_dbcheck-oldrelease.sh,v 1.1 2015/05/12 12:19:52 ryoon Exp $

ERROR: [check-portability.awk] 

--- testprogs/blackbox/dbcheck-oldrelease.sh.orig	2013-09-27 19:35:31.000000000 +0900
+++ testprogs/blackbox/dbcheck-oldrelease.sh	2013-11-02 11:59:48.000000000 +0900
@@ -55,19 +55,19 @@ dbcheck_acl_reset_clean() {
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
