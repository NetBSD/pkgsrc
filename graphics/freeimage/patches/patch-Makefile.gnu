$NetBSD: patch-Makefile.gnu,v 1.3 2025/05/14 13:05:52 adam Exp $

- Unbundle image libraries.
- Link with CXX for libstdc++.
- Link correctly on Darwin.
- Fix installation.

--- Makefile.gnu.orig	2015-03-10 08:04:00.000000000 +0000
+++ Makefile.gnu
@@ -13,6 +13,9 @@ DOS2UNIX = dos2unix
 
 LIBRARIES = -lstdc++
 
+INCLUDE += $(shell pkg-config --cflags libjpeg OpenEXR libopenjp2 libraw libpng libtiff-4 libwebp libwebpmux zlib)
+LDFLAGS += $(shell pkg-config --libs libjpeg OpenEXR libopenjp2 libraw libpng libtiff-4 libwebp libwebpmux zlib)
+
 MODULES = $(SRCS:.c=.o)
 MODULES := $(MODULES:.cpp=.o)
 CFLAGS ?= -O3 -fPIC -fexceptions -fvisibility=hidden
@@ -28,23 +31,28 @@ CXXFLAGS ?= -O3 -fPIC -fexceptions -fvis
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
+ifeq ($(shell uname),Darwin)
+SHAREDLIB = lib$(TARGET)-$(VER_MAJOR).$(VER_MINOR).dylib
+LIBNAME	= lib$(TARGET).dylib
+VERLIBNAME = lib$(TARGET).$(VER_MAJOR).dylib
+LDFLAGS += -Wl,-install_name,${PREFIX}/lib/$(SHAREDLIB)
+else
+SHLIB_EXT = so
 SHAREDLIB = lib$(TARGET)-$(VER_MAJOR).$(VER_MINOR).so
 LIBNAME	= lib$(TARGET).so
 VERLIBNAME = $(LIBNAME).$(VER_MAJOR)
+LDFLAGS += -Wl,-soname,$(VERLIBNAME)
+endif
 HEADER = Source/FreeImage.h
 
-
-
 default: all
 
-all: dist
+all: FreeImage
 
 dist: FreeImage
 	mkdir -p Dist
@@ -67,13 +75,12 @@ $(STATICLIB): $(MODULES)
 	$(AR) r $@ $(MODULES)
 
 $(SHAREDLIB): $(MODULES)
-	$(CC) -s -shared -Wl,-soname,$(VERLIBNAME) $(LDFLAGS) -o $@ $(MODULES) $(LIBRARIES)
+	$(CXX) -s -shared $(LDFLAGS) -o $@ $(MODULES)
 
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
