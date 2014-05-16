$NetBSD: patch-solenv_gbuild_Deliver.mk,v 1.1 2014/05/16 11:53:56 ryoon Exp $

* touch(1) of OpenBSD 5.5 does not support -h option

--- solenv/gbuild/Deliver.mk.orig	2014-04-30 19:49:45.000000000 +0000
+++ solenv/gbuild/Deliver.mk
@@ -51,7 +51,7 @@ endif
 endef
 
 define gb_Deliver__deliver
-$(if $(gb_Deliver_CLEARONDELIVER),rm -f $(2) &&) $(if $(gb_Deliver_HARDLINK),ln,cp -P -f) $(1) $(2) && touch -hr $(1) $(2)
+$(if $(gb_Deliver_CLEARONDELIVER),rm -f $(2) &&) $(if $(gb_Deliver_HARDLINK),ln,cp -P -f) $(1) $(2) && touch -r $(1) $(2)
 endef
 
 ifneq ($(strip $(gb_Deliver_GNUCOPY)),)
