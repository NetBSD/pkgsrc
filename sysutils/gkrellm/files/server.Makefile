include ../Makefile.inc

PACKAGE_D ?= gkrellmd

PKG_INCLUDE = `$(PKG_CONFIG) --cflags glib-2.0 gthread-2.0`
PKG_LIB = `$(PKG_CONFIG) --libs glib-2.0 gthread-2.0`

GLIB12_INCLUDE = `glib-config --cflags gthread`
GLIB12_LIB = `glib-config --libs gthread`

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


override CFLAGS += -Wall $(FLAGS)

OBJS =	main.o monitor.o mail.o glib.o sysdeps-unix.o

all:	build

build:	gkrellmd

gkrellmd static: $(OBJS)
	$(CC) $(OBJS) -o gkrellmd$(if $(findstring static,$@),.static -static) $(LIBS) $(LINK_FLAGS)

install:
	$(INSTALL_DIR) $(SINSTALLDIR)
	$(INSTALL_DIR) $(SMANDIR)
	$(INSTALL_BIN) $(STRIP) gkrellmd $(SINSTALLDIR)/$(PACKAGE_D)
	$(INSTALL_DATA) ../gkrellmd.1 $(SMANDIR)/$(PACKAGE_D).1

uninstall:
	rm -f $(SINSTALLDIR)/$(PACKAGE_D)
	rm -f $(SMANDIR)/$(PACKAGE_D).1

clean:
	rm -f *.o *~ *.bak gkrellmd core

SYSDEPS = ../src/sysdeps/bsd-common.c ../src/sysdeps/bsd-net-open.c \
	../src/sysdeps/freebsd.c ../src/sysdeps/gtop.c \
	../src/sysdeps/linux.c ../src/sysdeps/netbsd.c \
	../src/sysdeps/openbsd.c ../src/sysdeps/solaris.c ../src/sysdeps/darwin.c

main.o:		main.c gkrellmd.h
monitor.o:	monitor.c gkrellmd.h 
mail.o:		mail.c gkrellmd.h
glib.o:		glib.c gkrellmd.h
sysdeps-unix.o: sysdeps-unix.c gkrellmd.h ../src/gkrellm-sysdeps.h $(SYSDEPS)
