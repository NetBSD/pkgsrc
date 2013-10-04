$NetBSD: patch-sysui_CustomTarget__slackware.mk,v 1.1 2013/10/04 14:44:46 ryoon Exp $

* Fix unprivileged build.

--- sysui/CustomTarget_slackware.mk.orig	2013-08-21 11:40:03.000000000 +0000
+++ sysui/CustomTarget_slackware.mk
@@ -25,7 +25,7 @@ $(foreach product,$(PRODUCTLIST),\
 
 $(slack_WORKDIR)/empty.tar:
 	mkdir $(slack_WORKDIR)/empty
-	$(GNUTAR) -C $(slack_WORKDIR)/empty --owner=root $(if $(filter-out MACOSX,$(OS_FOR_BUILD)),--group=root) --same-owner -cf $@ .
+	$(GNUTAR) -C $(slack_WORKDIR)/empty --owner=${ROOT_USER} $(if $(filter-out MACOSX,$(OS_FOR_BUILD)),--group=${ROOT_GROUP}) --same-owner -cf $@ .
 
 $(slack_WORKDIR)/%/install/doinst.sh: $(slack_SRCDIR)/update-script $(call gb_CustomTarget_get_workdir,sysui/share)/%/launcherlist
 	echo "( cd etc; rm -rf $(UNIXFILENAME.$*) )" > $@
@@ -54,7 +54,7 @@ $(slack_WORKDIR)/%$(PRODUCTVERSION)-slac
            GNOMEDIR="" \
            ./create_tree.sh
 	cp $(slack_WORKDIR)/empty.tar $@.tmp
-	$(GNUTAR) -C $(slack_WORKDIR)/$* --owner=root $(if $(filter-out MACOSX,$(OS_FOR_BUILD)),--group=root) --same-owner \
+	$(GNUTAR) -C $(slack_WORKDIR)/$* --owner=${ROOT_USER} $(if $(filter-out MACOSX,$(OS_FOR_BUILD)),--group=${ROOT_GROUP}) --same-owner \
 		-rf $@.tmp install usr opt
 	gzip < $@.tmp > $@
 
