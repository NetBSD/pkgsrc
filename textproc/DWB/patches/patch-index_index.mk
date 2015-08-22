$NetBSD: patch-index_index.mk,v 1.1 2015/08/22 20:51:31 leot Exp $

Propagate make error

--- index/index.mk.orig	2015-05-18 16:16:13.000000000 +0200
+++ index/index.mk	2015-05-18 16:16:28.000000000 +0200
@@ -67,7 +67,7 @@
 	if [ -d $@ -a -f $@/$@.mk ]; then \
 	    cd $@; \
 	    echo "---- Making $(ACTION) in directory $(CURRENTDIR)/$@ ----"; \
-	    $(MAKE) -e -f $@.mk MAKE=$(MAKE) $(ACTION); \
+	    $(MAKE) -e -f $@.mk MAKE=$(MAKE) $(ACTION) && \
 	    echo; \
 	fi
 
