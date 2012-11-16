$NetBSD: patch-estic_make_freebsd-x.mak,v 1.1 2012/11/16 00:37:46 joerg Exp $

--- estic/make/freebsd-x.mak.orig	1997-01-31 03:57:24.000000000 +0000
+++ estic/make/freebsd-x.mak
@@ -27,22 +27,20 @@ AS = gas
 AR = ar
 LD = ld
 ZIP = zip
-CC = g++
 
 LIB	= ../spunk/spunk.a
 INCDIR	= ../spunk
 
-CFLAGS	= -DFREEBSD -g -Wall -I$(INCDIR) -x c++ -L /usr/X11R6/lib -fno-implicit-templates -DEXPLICIT_TEMPLATES
-
+CFLAGS	+= $(CPPFLAGS) -Wall -I$(INCDIR) -fno-implicit-templates -DEXPLICIT_TEMPLATES
 
 # ------------------------------------------------------------------------------
 # Implicit rules
 
 .c.o:
-	$(CC) $(CFLAGS) -c $<
+	$(CC) $(CFLAGS) -c $< -o $@
 
 .cc.o:
-	$(CC) $(CFLAGS) -c $<
+	$(CXX) $(CFLAGS) -c $< -o $@
 
 # ------------------------------------------------------------------------------
 # All OBJ files
@@ -71,18 +69,19 @@ OBJS =		callwin.o	\
 		icintcon.o	\
 		iclog.o		\
 		icmsgwin.o	\
-		icprefix.o	\
 		icshort.o	\
 		icver.o		\
 		istecmsg.o
 
+ACOBJ =		../areacode/areacode.o
+
 # ------------------------------------------------------------------------------
 #
 
 all:	xestic
 
-xestic: $(LIB) $(OBJS)
-	$(CC) -o xestic $(OBJS) $(LIB) -ltermcap -lg++ -lX11
+xestic: $(LIB) $(OBJS) $(ACOBJ)
+	$(CXX) -o xestic $(OBJS) $(ACOBJ) $(LIB) $(LDFLAGS) -ltermcap -lX11
 
 
 # ------------------------------------------------------------------------------
@@ -90,7 +89,7 @@ xestic: $(LIB) $(OBJS)
 
 depend dep:
 	@echo "Creating dependency information"
-	$(CC) -I$(INCDIR) -DFREEBSD -MM *.cc > .depend
+	$(CXX) -I$(INCDIR) -DFREEBSD -MM *.cc > .depend
 
 # ------------------------------------------------------------------------------
 # Create a ZIP file
