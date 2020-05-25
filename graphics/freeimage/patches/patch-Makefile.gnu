$NetBSD: patch-Makefile.gnu,v 1.2 2020/05/25 12:24:37 nia Exp $

- Unbundle image libraries.
- Link with CXX for libstdc++.
- Fix installation.

--- Makefile.gnu.orig	2015-03-10 09:04:00.000000000 +0000
+++ Makefile.gnu
@@ -13,6 +13,9 @@ DOS2UNIX = dos2unix
 
 LIBRARIES = -lstdc++
 
+INCLUDE += $(shell pkg-config --cflags libjpeg OpenEXR libopenjp2 libraw libpng libtiff-4 libwebp libwebpmux zlib)
+LDFLAGS += $(shell pkg-config --libs libjpeg OpenEXR libopenjp2 libraw libpng libtiff-4 libwebp libwebpmux zlib)
+
 MODULES = $(SRCS:.c=.o)
 MODULES := $(MODULES:.cpp=.o)
 CFLAGS ?= -O3 -fPIC -fexceptions -fvisibility=hidden
@@ -28,10 +31,8 @@ CXXFLAGS ?= -O3 -fPIC -fexceptions -fvis
 CXXFLAGS += -D__ANSI__
 CXXFLAGS += $(INCLUDE)
 
-ifeq ($(shell sh -c 'uname -m 2>/dev/null || echo not'),x86_64)
-	CFLAGS += -fPIC
-	CXXFLAGS += -fPIC
-endif
+CFLAGS += -fPIC
+CXXFLAGS += -fPIC
 
 TARGET  = freeimage
 STATICLIB = lib$(TARGET).a
@@ -40,8 +41,6 @@ LIBNAME	= lib$(TARGET).so
 VERLIBNAME = $(LIBNAME).$(VER_MAJOR)
 HEADER = Source/FreeImage.h
 
-
-
 default: all
 
 all: dist
@@ -67,13 +66,12 @@ $(STATICLIB): $(MODULES)
 	$(AR) r $@ $(MODULES)
 
 $(SHAREDLIB): $(MODULES)
-	$(CC) -s -shared -Wl,-soname,$(VERLIBNAME) $(LDFLAGS) -o $@ $(MODULES) $(LIBRARIES)
+	$(CXX) -s -shared -Wl,-soname,$(VERLIBNAME) $(LDFLAGS) -o $@ $(MODULES)
 
 install:
-	install -d $(INCDIR) $(INSTALLDIR)
-	install -m 644 -o root -g root $(HEADER) $(INCDIR)
-	install -m 644 -o root -g root $(STATICLIB) $(INSTALLDIR)
-	install -m 755 -o root -g root $(SHAREDLIB) $(INSTALLDIR)
+	$(BSD_INSTALL_DATA) $(HEADER) $(INCDIR)
+	$(BSD_INSTALL_DATA) $(STATICLIB) $(INSTALLDIR)
+	$(BSD_INSTALL_LIB) $(SHAREDLIB) $(INSTALLDIR)
 	ln -sf $(SHAREDLIB) $(INSTALLDIR)/$(VERLIBNAME)
 	ln -sf $(VERLIBNAME) $(INSTALLDIR)/$(LIBNAME)	
 #	ldconfig
