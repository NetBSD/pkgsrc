$NetBSD: patch-text_text.mk,v 1.1 2015/08/22 20:51:31 leot Exp $

Propagate make error

--- text/text.mk.orig	2015-05-18 16:22:00.000000000 +0200
+++ text/text.mk	2015-05-18 16:22:12.000000000 +0200
@@ -91,7 +91,7 @@
 	if [ -d $@ -a -f $@/$@.mk ]; then \
 	    cd $@; \
 	    echo "---- Making $(ACTION) in directory $(CURRENTDIR)/$@ ----"; \
-	    $(MAKE) -e -f $@.mk MAKE=$(MAKE) $(ACTION); \
+	    $(MAKE) -e -f $@.mk MAKE=$(MAKE) $(ACTION) && \
 	    echo; \
 	fi
 
