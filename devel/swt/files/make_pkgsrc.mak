# $NetBSD: make_pkgsrc.mak,v 1.4 2012/12/24 04:04:38 dholland Exp $
#*******************************************************************************
# Copyright (c) 2000, 2009 IBM Corporation and others.
# All rights reserved. This program and the accompanying materials
# are made available under the terms of the Eclipse Public License v1.0
# which accompanies this distribution, and is available at
# http://www.eclipse.org/legal/epl-v10.html
#
# Contributors:
#     IBM Corporation - initial API and implementation
#*******************************************************************************

# Makefile for creating SWT libraries for Linux GTK

include make_common.mak

SWT_VERSION=$(maj_ver)$(min_ver)

# Define the various shared libraries to be build.
WS_PREFIX = gtk
SWT_PREFIX = swt
CDE_PREFIX = swt-cde
AWT_PREFIX = swt-awt
SWTPI_PREFIX = swt-pi
CAIRO_PREFIX = swt-cairo
ATK_PREFIX = swt-atk
GNOME_PREFIX = swt-gnome
MOZILLA_PREFIX = swt-mozilla$(GCC_VERSION)
XULRUNNER_PREFIX = swt-xulrunner
XPCOMINIT_PREFIX = swt-xpcominit
GLX_PREFIX = swt-glx

SWT_LIB = lib$(SWT_PREFIX)-$(WS_PREFIX)-$(SWT_VERSION).so
CDE_LIB = lib$(CDE_PREFIX)-$(WS_PREFIX)-$(SWT_VERSION).so
AWT_LIB = lib$(AWT_PREFIX)-$(WS_PREFIX)-$(SWT_VERSION).so
SWTPI_LIB = lib$(SWTPI_PREFIX)-$(WS_PREFIX)-$(SWT_VERSION).so
CAIRO_LIB = lib$(CAIRO_PREFIX)-$(WS_PREFIX)-$(SWT_VERSION).so
ATK_LIB = lib$(ATK_PREFIX)-$(WS_PREFIX)-$(SWT_VERSION).so
GNOME_LIB = lib$(GNOME_PREFIX)-$(WS_PREFIX)-$(SWT_VERSION).so
MOZILLA_LIB = lib$(MOZILLA_PREFIX)-$(WS_PREFIX)-$(SWT_VERSION).so
XULRUNNER_LIB = lib$(XULRUNNER_PREFIX)-$(WS_PREFIX)-$(SWT_VERSION).so
XPCOMINIT_LIB = lib$(XPCOMINIT_PREFIX)-$(WS_PREFIX)-$(SWT_VERSION).so
GLX_LIB = lib$(GLX_PREFIX)-$(WS_PREFIX)-$(SWT_VERSION).so

CAIROCFLAGS = `pkg-config --cflags cairo`
CAIROLIBS = `pkg-config --libs-only-L cairo` `pkg-config --libs-only-other cairo` -lcairo

# Do not use pkg-config to get libs because it includes unnecessary dependencies (i.e. pangoxft-1.0)
GTKCFLAGS = `pkg-config --cflags gtk+-2.0`
GTKLIBS = `pkg-config --libs-only-L gtk+-2.0 gthread-2.0` `pkg-config --libs-only-other gtk+-2.0 gthread-2.0` -lgtk-x11-2.0 -lgthread-2.0 `pkg-config --libs xtst`

CDE_LIBS = -L$(CDE_HOME)/lib -R$(CDE_HOME)/lib -lXt -lX11 -lDtSvc

AWT_LIBS = -L$(JAVA_HOME)/jre/lib/$(LOWER_ARCH) -R$(JAVA_HOME)/jre/lib/$(LOWER_ARCH) -ljawt -shared

ATKCFLAGS = `pkg-config --cflags atk gtk+-2.0`
ATKLIBS = `pkg-config --libs-only-L atk gtk+-2.0` `pkg-config --libs-only-other atk gtk+-2.0` -latk-1.0 -lgtk-x11-2.0

GNOMECFLAGS = `pkg-config --cflags gnome-vfs-module-2.0 libgnome-2.0 libgnomeui-2.0`
GNOMELIBS = `pkg-config --libs-only-L gnome-vfs-module-2.0 libgnome-2.0 libgnomeui-2.0` `pkg-config --libs-only-other gnome-vfs-module-2.0 libgnome-2.0 libgnomeui-2.0` -lgnomevfs-2 -lgnome-2 -lgnomeui-2

GLXCFLAGS = `pkg-config --cflags gl`
GLXLIBS = -shared -fPIC `pkg-config --libs gl x11` -lGLU -lm

# Uncomment for Native Stats tool
#NATIVE_STATS = -DNATIVE_STATS

MOZILLACFLAGS = -O \
	-DSWT_VERSION=$(SWT_VERSION) \
	$(NATIVE_STATS) \
	-DMOZILLA_STRICT_API=1 \
	-fno-rtti \
	-fno-exceptions \
	-Wall \
	-Wno-non-virtual-dtor \
	-fPIC \
	-I. \
	-I$(JAVA_HOME)/include \
	-I$(JAVA_HOME)/include/$(LOWER_OPSYS) \
	${SWT_PTR_CFLAGS}
MOZILLALIBS = -shared -Wl,--version-script=mozilla_exports -Bsymbolic
MOZILLAEXCLUDES = -DNO__1XPCOMGlueShutdown \
	-DNO__1XPCOMGlueStartup \
	-DNO__1XPCOMGlueLoadXULFunctions \
	-DNO_memmove__ILorg_eclipse_swt_internal_mozilla_nsDynamicFunctionLoad_2I \
	-DNO_memmove__JLorg_eclipse_swt_internal_mozilla_nsDynamicFunctionLoad_2J \
	-DNO_nsDynamicFunctionLoad_1sizeof \
	-DNO__1Call__IIIIII \
	-DNO__1Call__JJJJJI \
	-DNO_nsDynamicFunctionLoad
XULRUNNEREXCLUDES = -DNO__1NS_1InitXPCOM2

XULRUNNER_INCLUDES = `pkg-config --cflags libxul-embedding`
XULRUNNER_LIBS = `pkg-config --libs libxul-embedding`

SWT_OBJECTS = swt.o c.o c_stats.o callback.o
CDE_OBJECTS = swt.o cde.o cde_structs.o cde_stats.o
AWT_OBJECTS = swt_awt.o
SWTPI_OBJECTS = swt.o os.o os_structs.o os_custom.o os_stats.o
CAIRO_OBJECTS = swt.o cairo.o cairo_structs.o cairo_stats.o
ATK_OBJECTS = swt.o atk.o atk_structs.o atk_custom.o atk_stats.o
GNOME_OBJECTS = swt.o gnome.o gnome_structs.o gnome_stats.o
MOZILLA_OBJECTS = swt.o xpcom.o xpcom_custom.o xpcom_structs.o xpcom_stats.o
XULRUNNER_OBJECTS = swt.o xpcomxul.o xpcomxul_custom.o xpcomxul_structs.o xpcomxul_stats.o
XPCOMINIT_OBJECTS = swt.o xpcominit.o xpcominit_structs.o xpcominit_stats.o
GLX_OBJECTS = swt.o glx.o glx_structs.o glx_stats.o

CFLAGS = -O -Wall \
		-DSWT_VERSION=$(SWT_VERSION) \
		$(NATIVE_STATS) \
		-DLINUX -DGTK \
		-I$(JAVA_HOME)/include \
		-I$(JAVA_HOME)/include/$(LOWER_OPSYS) \
		-fPIC \
		${SWT_PTR_CFLAGS}
LIBS = -shared -fPIC

ifndef NO_STRIP
	AWT_LIBS := $(AWT_LIBS) -s
	MOZILLALIBS := $(MOZILLALIBS) -s
	LIBS := $(LIBS) -s
endif

all: make_swt make_atk make_gnome make_glx

#
# SWT libs
#
make_swt: $(SWT_LIB) $(SWTPI_LIB)

$(SWT_LIB): $(SWT_OBJECTS)
	$(CC) $(LIBS) -o $(SWT_LIB) $(SWT_OBJECTS)

callback.o: callback.c callback.h
	$(CC) $(CFLAGS) -DUSE_ASSEMBLER -c callback.c

$(SWTPI_LIB): $(SWTPI_OBJECTS)
	$(CC) $(LIBS) $(GTKLIBS) -o $(SWTPI_LIB) $(SWTPI_OBJECTS)

swt.o: swt.c swt.h
	$(CC) $(CFLAGS) -c swt.c
os.o: os.c os.h swt.h os_custom.h
	$(CC) $(CFLAGS) $(GTKCFLAGS) -c os.c
os_structs.o: os_structs.c os_structs.h os.h swt.h
	$(CC) $(CFLAGS) $(GTKCFLAGS) -c os_structs.c 
os_custom.o: os_custom.c os_structs.h os.h swt.h
	$(CC) $(CFLAGS) $(GTKCFLAGS) -c os_custom.c
os_stats.o: os_stats.c os_structs.h os.h os_stats.h swt.h
	$(CC) $(CFLAGS) $(GTKCFLAGS) -c os_stats.c

#
# CAIRO libs
#
make_cairo: $(CAIRO_LIB)

$(CAIRO_LIB): $(CAIRO_OBJECTS)
	$(CC) $(LIBS) $(CAIROLIBS) -o $(CAIRO_LIB) $(CAIRO_OBJECTS)

cairo.o: cairo.c cairo.h swt.h
	$(CC) $(CFLAGS) $(CAIROCFLAGS) -c cairo.c
cairo_structs.o: cairo_structs.c cairo_structs.h cairo.h swt.h
	$(CC) $(CFLAGS) $(CAIROCFLAGS) -c cairo_structs.c
cairo_stats.o: cairo_stats.c cairo_structs.h cairo.h cairo_stats.h swt.h
	$(CC) $(CFLAGS) $(CAIROCFLAGS) -c cairo_stats.c

#
# CDE lib
#

make_cde: $(CDE_LIB)

$(CDE_LIB): $(CDE_OBJECTS)
	$(CC) $(LIBS) $(CDE_LIBS) -o $(CDE_LIB) $(CDE_OBJECTS)

#
# AWT lib
#
make_awt:$(AWT_LIB)

$(AWT_LIB): $(AWT_OBJECTS)
	$(CC) $(AWT_LIBS) -o $(AWT_LIB) $(AWT_OBJECTS)

#
# Atk lib
#
make_atk: $(ATK_LIB)

$(ATK_LIB): $(ATK_OBJECTS)
	$(CC) $(LIBS) $(ATKLIBS) -o $(ATK_LIB) $(ATK_OBJECTS)

atk.o: atk.c atk.h
	$(CC) $(CFLAGS) $(ATKCFLAGS) -c atk.c
atk_structs.o: atk_structs.c atk_structs.h atk.h
	$(CC) $(CFLAGS) $(ATKCFLAGS) -c atk_structs.c
atk_custom.o: atk_custom.c atk_structs.h atk.h
	$(CC) $(CFLAGS) $(ATKCFLAGS) -c atk_custom.c
atk_stats.o: atk_stats.c atk_structs.h atk_stats.h atk.h
	$(CC) $(CFLAGS) $(ATKCFLAGS) -c atk_stats.c

#
# Gnome lib
#
make_gnome: $(GNOME_LIB)

$(GNOME_LIB): $(GNOME_OBJECTS)
	$(CC) $(LIBS) $(GNOMELIBS) -o $(GNOME_LIB) $(GNOME_OBJECTS)

gnome.o: gnome.c 
	$(CC) $(CFLAGS) $(GNOMECFLAGS) -c gnome.c

gnome_structs.o: gnome_structs.c 
	$(CC) $(CFLAGS) $(GNOMECFLAGS) -c gnome_structs.c
	
gnome_stats.o: gnome_stats.c gnome_stats.h
	$(CC) $(CFLAGS) $(GNOMECFLAGS) -c gnome_stats.c

#
# Mozilla lib
#
make_mozilla:$(MOZILLA_LIB)

$(MOZILLA_LIB): $(MOZILLA_OBJECTS)
	$(CXX) -o $(MOZILLA_LIB) $(MOZILLA_OBJECTS) $(MOZILLALIBS) ${MOZILLA_LIBS}

xpcom.o: xpcom.cpp
	$(CXX) $(MOZILLACFLAGS) $(MOZILLAEXCLUDES) ${MOZILLA_INCLUDES} -c xpcom.cpp

xpcom_structs.o: xpcom_structs.cpp
	$(CXX) $(MOZILLACFLAGS) $(MOZILLAEXCLUDES) ${MOZILLA_INCLUDES} -c xpcom_structs.cpp
	
xpcom_custom.o: xpcom_custom.cpp
	$(CXX) $(MOZILLACFLAGS) $(MOZILLAEXCLUDES) ${MOZILLA_INCLUDES} -c xpcom_custom.cpp

xpcom_stats.o: xpcom_stats.cpp
	$(CXX) $(MOZILLACFLAGS) $(MOZILLAEXCLUDES) ${MOZILLA_INCLUDES} -c xpcom_stats.cpp

#
# XULRunner lib
#
make_xulrunner:$(XULRUNNER_LIB)

$(XULRUNNER_LIB): $(XULRUNNER_OBJECTS)
	$(CXX) -o $(XULRUNNER_LIB) $(XULRUNNER_OBJECTS) $(MOZILLALIBS) ${XULRUNNER_LIBS}

xpcomxul.o: xpcom.cpp
	$(CXX) -o xpcomxul.o $(MOZILLACFLAGS) $(XULRUNNEREXCLUDES) ${XULRUNNER_INCLUDES} -c xpcom.cpp

xpcomxul_structs.o: xpcom_structs.cpp
	$(CXX) -o xpcomxul_structs.o $(MOZILLACFLAGS) $(XULRUNNEREXCLUDES) ${XULRUNNER_INCLUDES} -c xpcom_structs.cpp
	
xpcomxul_custom.o: xpcom_custom.cpp
	$(CXX) -o xpcomxul_custom.o $(MOZILLACFLAGS) $(XULRUNNEREXCLUDES) ${XULRUNNER_INCLUDES} -c xpcom_custom.cpp

xpcomxul_stats.o: xpcom_stats.cpp
	$(CXX) -o xpcomxul_stats.o $(MOZILLACFLAGS) $(XULRUNNEREXCLUDES) ${XULRUNNER_INCLUDES} -c xpcom_stats.cpp

#
# XPCOMInit lib
#
make_xpcominit:$(XPCOMINIT_LIB)

$(XPCOMINIT_LIB): $(XPCOMINIT_OBJECTS)
	$(CXX) -o $(XPCOMINIT_LIB) $(XPCOMINIT_OBJECTS) $(MOZILLALIBS) ${XULRUNNER_LIBS}

xpcominit.o: xpcominit.cpp
	$(CXX) $(MOZILLACFLAGS) ${XULRUNNER_INCLUDES} -c xpcominit.cpp

xpcominit_structs.o: xpcominit_structs.cpp
	$(CXX) $(MOZILLACFLAGS) ${XULRUNNER_INCLUDES} -c xpcominit_structs.cpp
	
xpcominit_stats.o: xpcominit_stats.cpp
	$(CXX) $(MOZILLACFLAGS) ${XULRUNNER_INCLUDES} -c xpcominit_stats.cpp

#
# GLX lib
#
make_glx: $(GLX_LIB)

$(GLX_LIB): $(GLX_OBJECTS)
	$(CC) $(LIBS) $(GLXLIBS) -o $(GLX_LIB) $(GLX_OBJECTS)

glx.o: glx.c 
	$(CC) $(CFLAGS) $(GLXCFLAGS) -c glx.c

glx_structs.o: glx_structs.c 
	$(CC) $(CFLAGS) $(GLXCFLAGS) -c glx_structs.c
	
glx_stats.o: glx_stats.c glx_stats.h
	$(CC) $(CFLAGS) $(GLXCFLAGS) -c glx_stats.c

#
# Install
#
install: all
	cp *.so $(OUTPUT_DIR)

#
# Clean
#
clean:
	rm -f *.o *.so
