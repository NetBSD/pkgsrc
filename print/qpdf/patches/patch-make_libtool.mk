$NetBSD: patch-make_libtool.mk,v 1.2 2013/02/12 12:35:36 drochner Exp $

Sent upstream, will be fixed in 4.1.0.

--- make/libtool.mk.orig	2013-01-17 14:51:04.000000000 +0000
+++ make/libtool.mk
@@ -1,7 +1,7 @@
 # --- Required interface definitions ---
 
 # LIBTOOL needs bash
-SHELL=/bin/bash
+#SHELL=/bin/bash
 
 OBJ=o
 LOBJ=lo
@@ -116,7 +116,6 @@ install: all
 		libqpdf/$(OUTPUT_DIR)/libqpdf.la \
 		$(DESTDIR)$(libdir)/libqpdf.la
 	$(LIBTOOL) --finish $(DESTDIR)$(libdir)
-	$(RM) $(DESTDIR)$(libdir)/libqpdf.la
 	$(LIBTOOL) --mode=install install -c \
 		qpdf/$(OUTPUT_DIR)/qpdf \
 		$(DESTDIR)$(bindir)/qpdf
