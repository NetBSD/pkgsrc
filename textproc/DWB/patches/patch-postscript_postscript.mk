$NetBSD: patch-postscript_postscript.mk,v 1.1 2015/08/22 20:51:31 leot Exp $

Propagate make error

--- postscript/postscript.mk.orig	2015-05-18 16:20:27.000000000 +0200
+++ postscript/postscript.mk	2015-05-18 16:20:43.000000000 +0200
@@ -197,7 +197,7 @@
 	if [ -d $@ -a -f $@/$@.mk ]; then  \
 	    cd $@; \
 	    echo "---- Making $(ACTION) in directory $(CURRENTDIR)/$@ ----"; \
-	    $(MAKE) -e -f $@.mk MAKE=$(MAKE) $(ACTION); \
+	    $(MAKE) -e -f $@.mk MAKE=$(MAKE) $(ACTION) && \
 	    echo; \
 	fi
 
