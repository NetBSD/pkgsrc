$NetBSD: patch-laserjet_laserjet.mk,v 1.1 2015/08/22 20:51:31 leot Exp $

Propagate make error

--- laserjet/laserjet.mk.orig	2015-05-18 16:17:23.000000000 +0200
+++ laserjet/laserjet.mk	2015-05-18 16:17:34.000000000 +0200
@@ -63,7 +63,7 @@
 	if [ -d $@ -a -f $@/$@.mk ]; then \
 	    cd $@; \
 	    echo "---- Making $(ACTION) in directory $(CURRENTDIR)/$@ ----"; \
-	    $(MAKE) -e -f $@.mk MAKE=$(MAKE) $(ACTION); \
+	    $(MAKE) -e -f $@.mk MAKE=$(MAKE) $(ACTION) && \
 	    echo; \
 	fi
 
