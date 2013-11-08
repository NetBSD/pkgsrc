$NetBSD: patch-stepmake_stepmake_po-targets.make,v 1.1 2013/11/08 21:17:56 joerg Exp $

--- stepmake/stepmake/po-targets.make.orig	2013-11-08 12:08:25.000000000 +0000
+++ stepmake/stepmake/po-targets.make
@@ -36,11 +36,11 @@ ifneq ($(strip $(ALL_PO_SOURCES)),)
 	xgettext $(XGETTEXT_OPTIONS) --output-dir=$(po-outdir) \
 	 --keyword=_ --keyword=_f --keyword=_i \
 	 $(XGETTEXT_FLAGS) $(ALL_PO_SOURCES)
-endif
-endif
 	sed -i '1,2d' $(po-outdir)/$(package).po
 	sed -i -e 's/^\# This file is distributed.*/$(sed-header)/' $(po-outdir)/$(package).po
 	sed -i -e 's/^\"Content-Type: text\/plain.*/$(sed-content)/' $(po-outdir)/$(package).po
+endif
+endif
 
 
 po-update: po
