include ../Makefile.inc

PACKAGE_D ?= gkrellmd
GKRELLMD_INCLUDES = gkrellmd.h

PKG_INCLUDE = `$(PKG_CONFIG) --cflags glib-2.0 gthread-2.0`
PKG_LIB = `$(PKG_CONFIG) --libs glib-2.0 gmodule-2.0 gthread-2.0`

GLIB12_INCLUDE = `glib-config --cflags`
GLIB12_LIB = `glib-config --libs glib gmodule`

USE_GLIB12?=	no
ifeq ($(glib12),1)
USE_GLIB12=	yes
endif
ifeq ($(glib12),yes)
USE_GLIB12=	yes
endif

CFLAGS?=	-O2
FLAGS = -I.. $(PKG_INCLUDE) $(GTOP_INCLUDE)
ifeq ($(USE_GLIB12),yes)
FLAGS = -I.. $(GLIB12_INCLUDE) $(GTOP_INCLUDE)
endif

FLAGS+= $(PTHREAD_INC)

LIBS = $(PKG_LIB) $(GTOP_LIBS_D) $(SYS_LIBS) 
ifeq ($(USE_GLIB12),yes)
LIBS = $(GLIB12_LIB) $(GTOP_LIBS_D) $(SYS_LIBS)
endif

ifeq ($(DEBUG),yes)
    FLAGS += -g
endif

ifeq ($(PROFILE),yes)
    FLAGS += -g -pg
endif

ifeq ($(ENABLE_NLS),1)
    FLAGS += -DENABLE_NLS -DLOCALEDIR=\"$(LOCALEDIR)\"
endif
ifneq ($(PACKAGE_D),gkrellmd)
	FLAGS += -DPACKAGE_D=\"$(PACKAGE_D)\"
endif

ifeq ($(HAVE_GETADDRINFO),1)
    FLAGS += -DHAVE_GETADDRINFO
endif

USE_LIBSENSORS?=	yes
ifeq ($(without-libsensors),yes)
USE_LIBSENSORS=		no
endif
ifeq ($(without-libsensors),1)
USE_LIBSENSORS=		no
endif
ifeq ($(USE_LIBSENSORS),no)
CONFIGURE_ARGS+=	--without-libsensors
endif

GREP?=		grep

DUMMY_VAR:=	$(shell ./configure $(CONFIGURE_ARGS))
HAVE_LIBSENSORS=	$(shell $(GREP) -c HAVE_LIBSENSORS configure.h)

ifeq ($(HAVE_LIBSENSORS),1)
SENSORS_LIBS?=	-lsensors
LIBS+=	$(SENSORS_LIBS)
endif

override CFLAGS += -Wall $(FLAGS)

OBJS =	main.o monitor.o mail.o plugins.o glib.o utils.o sysdeps-unix.o

all:	build

build:	gkrellmd

gkrellmd static: $(OBJS)
	$(CC) $(OBJS) -o gkrellmd$(if $(findstring static,$@),.static -static) $(LIBS) $(LINK_FLAGS)

install:
	$(INSTALL_DIR) $(SINSTALLDIR)
	$(INSTALL_BIN) $(STRIP) gkrellmd $(SINSTALLDIR)/$(PACKAGE_D)
	$(INSTALL_DIR) $(SMANDIR)
	$(INSTALL_DATA) ../gkrellmd.1 $(SMANDIR)/$(PACKAGE_D).1
	$(INSTALL_DIR) $(INCLUDEDIR)/gkrellm2
	$(INSTALL_DATA) $(GKRELLMD_INCLUDES) $(INCLUDEDIR)/gkrellm2

uninstall:
	rm -f $(SINSTALLDIR)/$(PACKAGE_D)
	rm -f $(SMANDIR)/$(PACKAGE_D).1

clean:
	rm -f *.o *~ *.bak configure.h configure.log gkrellmd core

SYSDEPS = ../src/sysdeps/bsd-common.c ../src/sysdeps/bsd-net-open.c \
	../src/sysdeps/freebsd.c ../src/sysdeps/gtop.c \
	../src/sysdeps/linux.c ../src/sysdeps/netbsd.c ../src/sysdeps/dragonfly.c  \
	../src/sysdeps/openbsd.c ../src/sysdeps/solaris.c ../src/sysdeps/darwin.c

main.o:		main.c gkrellmd.h
monitor.o:	monitor.c gkrellmd.h 
mail.o:		mail.c gkrellmd.h
plugins.o:	plugins.c gkrellmd.h
glib.o:		glib.c gkrellmd.h
utils.o:	utils.c gkrellmd.h
sysdeps-unix.o: sysdeps-unix.c gkrellmd.h ../src/gkrellm-sysdeps.h $(SYSDEPS)
