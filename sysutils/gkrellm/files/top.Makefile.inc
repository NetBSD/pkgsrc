VERSION=	2.2.10

# Path options
PREFIX?=	/usr/local
X11BASE?=	/nonexistent
INSTALLROOT?=	$(DESTDIR)$(PREFIX)
INSTALLDIR?=	$(INSTALLROOT)/bin
INCLUDEDIR?=	$(INSTALLROOT)/include
LOCALEDIR?=	$(INSTALLROOT)/share/locale
PKGCONFIGDIR?=	$(INSTALLROOT)/lib/pkgconfig
MANDIR?=	$(INSTALLROOT)/man/man1
SMANDIR?=	$(INSTALLROOT)/man/man1
SINSTALLDIR?=	$(INSTALLROOT)/bin

# Ownership and mode options
DATAMODE?=	0644
BINMODE?=	0755
BINOWNER?=	root
BINGROUP?=	root

# Tools paths
MSGFMT?=	msgfmt
MSGFMT_OPT?=	-f -v 
INSTALL?=	$(BSD_INSTALL)
PKG_CONFIG?=	pkg-config
STRIP?=		-s

# Helpers
INSTALL_DIR=	$(INSTALL) -d
INSTALL_DATA=	$(INSTALL) -c -m $(DATAMODE)
INSTALL_BIN=	$(INSTALL) -c -m $(BINMODE) -o $(BINOWNER) -g $(BINGROUP)

# Compilation options
ENABLE_NLS?=	yes
DEBUG?=		no
PROFILE?=	no
NEED_MD5?=	yes
MD5_LIBS?=
GKRELLM_CFLAGS?=
GTOP?=

# Vanilla GKrellM compatibility
ifeq ($(enable_nls),1)
ENABLE_NLS=	yes
endif
ifeq ($(enable_nls),yes)
ENABLE_NLS=	yes
endif
ifeq ($(debug),1)
DEBUG=		yes
endif
ifeq ($(debug),yes)
DEBUG=		yes
endif
ifeq ($(profile),1)
PROFILE=	yes
endif
ifeq ($(profile),yes)
PROFILE=	yes
endif

# Don't strip binaries if in DEBUG mode
ifeq ($(DEBUG),yes)
STRIP=
endif

ifeq ($(GTOP),)
# OS-specific overrides
SUPPORTED_OSES=	Linux NetBSD FreeBSD OpenBSD Darwin Solaris DragonFly

REALOPSYS=	$(shell uname -s)
OPSYS=		$(if $(findstring $(REALOPSYS),$(SUPPORTED_OSES)),$(REALOPSYS),Linux)
OSREV=		$(shell uname -r)

# Isn't this ugly?

ifeq ($(OPSYS),NetBSD)
SYS_LIBS=	-lkvm
BINGROUP=	kmem
NEED_MD5=	no
MD5_LIBS=
else
 ifeq ($(OPSYS),OpenBSD)
SYS_LIBS=	-lkvm -pthread
BINGROUP=	kmem
 else
  ifeq ($(OPSYS),FreeBSD)
BINGROUP=	kmem
NEED_MD5=	no
MD5_LIBS=	-lmd
   ifeq ($(filter 2.%,$(OSREV)),)
SYS_LIBS=	-lkvm -ldevstat
   else
SYS_LIBS=	-lkvm
   endif
  else
   ifeq ($(OPSYS),Darwin)
SYS_LIBS=	-lkvm -framework IOKit
LINK_FLAGS+=	-prebind -Wl,-bind_at_load -framework CoreFoundation -lX11
GTK_CONFIG=	gtk-config
STRIP=
NEED_MD5=	no
MD5_LIBS=
HAVE_GETADDRINFO=	1
    ifeq ($(MODULE),src)
LINK_FLAGS+=	-lX11
    endif
   else
    ifeq ($(OPSYS),Solaris)
MSGFMT_OPT=	-v 
CC?=		gcc
GKRELLM_CFLAGS=	-Wno-implicit-int
SYS_LIBS=	-lkstat -lkvm -ldevinfo
     ifeq ($(OSREV),5.8)
LINK_FLAGS=
SYS_LIBS+=	-lsocket -lintl
      ifeq ($(MODULE),src)
SYS_LIBS+=	-lresolv -lX11
      else # Well, we don't really care about po
SYS_LIBS+=	-lnsl
GKRELLM_CFLAGS=	-DSOLARIS_8
      endif
     else
SYS_LIBS+=	-lsocket
      ifeq ($(MODULE),src)
SYS_LIBS+=	-lresolv -lX11
      else
SYS_LIBS+=	-lnsl
      endif
     endif
    else
      ifeq (${OPSYS},DragonFly)
BINGROUP=	kmem
NEED_MD5=	no
MD5_LIBS=	-lmd
SYS_LIBS=	-lkvm -lkinfo -ldevstat
      endif
    endif
   endif
  endif
 endif
endif
else	# GTOP
LINK_FLAGS=
MD5_LIBS=
 ifeq ($(GTOP), gnome-gtop)
SYS_LIBS=	`gnome-config --libs libgtop`
GKRELLM_CFLAGS=	`gnome-config --cflags libgtop`
 else
  ifeq ($(GTOP), gtop)
SYS_LIBS=	`libgtop-config --libs`
GKRELLM_CFLAGS=	`libgtop-config --cflags`
  else	# gtop1.0 by default
GTOP_PREFIX?=	/usr
GKRELLM_CFLAGS=	-I$(GTOP_PREFIX)/include
SYS_LIBS=	-L$(GTOP_PREFIX)/lib -lgtop -lgtop_common -lgtop_sysdeps
   ifeq ($(MODULE),src)
SYS_LIBS+=	-lXau
   endif
  endif
 endif
endif

CFLAGS+=	$(GKRELLM_CFLAGS)
