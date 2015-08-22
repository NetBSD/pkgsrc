$NetBSD: patch-text_pm_pm.mk,v 1.1 2015/08/22 20:51:31 leot Exp $

Change tmac file mode, force C++ for .c files

--- text/pm/pm.mk.orig	2015-05-17 18:28:51.000000000 +0200
+++ text/pm/pm.mk	2015-05-19 16:44:26.000000000 +0200
@@ -3,7 +3,6 @@
 #
 
 #CC=CC
-CC=$(CXX)
 
 MAKE=/bin/make
 MAKEFILE=pm.mk
@@ -37,11 +36,11 @@
 	@chgrp $(GROUP) $(TMACDIR)/pm
 	@chown $(OWNER) $(TMACDIR)/pm
 	cp tmac.pm $(TMACDIR)/tmac.pm
-	@chmod 664 $(TMACDIR)/tmac.pm
+	@chmod 644 $(TMACDIR)/tmac.pm
 	@chgrp $(GROUP) $(TMACDIR)/tmac.pm
 	@chown $(OWNER) $(TMACDIR)/tmac.pm
 	cp tmac.spe $(TMACDIR)/tmac.spe
-	@chmod 664 $(TMACDIR)/tmac.spe
+	@chmod 644 $(TMACDIR)/tmac.spe
 	@chgrp $(GROUP) $(TMACDIR)/tmac.spe
 	@chown $(OWNER) $(TMACDIR)/tmac.spe
 	sed -e 's" /usr/lib/tmac$$" $(TMACDIR)"' \
@@ -66,8 +65,11 @@
 	    -e "s:TMACDIR:$(TMACDIR):" \
 	tmac.spe.sr >tmac.spe
 
+.c.o:
+	$(CXX) $(CFLAGS) -c $<
+
 pm : $(OFILES)
-	$(CC) $(CFLAGS) -o pm $(OFILES) -lm
+	$(CXX) $(CFLAGS) -o pm $(OFILES) -lm
 
 misc.o : misc.h
 slug.o : slug.h misc.h
