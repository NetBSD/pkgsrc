# $NetBSD: Makefile,v 1.84 2016/02/25 12:50:49 jperkin Exp $

DISTNAME=		bochs-2.6.8
PKGREVISION=		1
CATEGORIES=		emulators
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=bochs/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://bochs.sourceforge.net/
COMMENT=		IA32 and AMD64 PC emulator
LICENSE=		gnu-lgpl-v2.1

MAKE_JOBS_SAFE=		no

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake gunzip gzip
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes

ONLY_FOR_COMPILER=	gcc
CXXFLAGS+=		-DPARANOID

CONFIGURE_ARGS+=	--enable-cdrom
CONFIGURE_ARGS+=	--enable-ne2000

MAKE_ENV+=		GZIP_CMD=${GZIP_CMD:Q}
MAKE_ENV+=		GUNZIP_CMD=${GUNZIP_CMD:Q}
MAKE_ENV+=		WGET=${FETCH_CMD:Q}

PLIST_VARS+=		debug notiny nox11 plugins x11

PKG_OPTIONS_VAR=	PKG_OPTIONS.bochs
PKG_SUPPORTED_OPTIONS+=	debug tiny x11
PKG_SUGGESTED_OPTIONS+=	x11

.include "../../mk/bsd.prefs.mk"
.include "../../mk/bsd.options.mk"

# Debugging features for the client operating systems. These options are
# not enabled by default because they can adversely impact performance.
.if !empty(PKG_OPTIONS:Mdebug)
CONFIGURE_ARGS+=	--disable-plugins
CONFIGURE_ARGS+=	--enable-debugger
CONFIGURE_ARGS+=	--enable-disasm
CONFIGURE_ARGS+=	--enable-iodebug
CONFIGURE_ARGS+=	--enable-x86-debugger
.endif

.if empty(PKG_OPTIONS:Mtiny)
PLIST.notiny=		yes

CONFIGURE_ARGS+=	--enable-idle-hack
CONFIGURE_ARGS+=	--enable-a20-pin
CONFIGURE_ARGS+=	--enable-x86-64
CONFIGURE_ARGS+=	--enable-smp
CONFIGURE_ARGS+=	--enable-long-phy-address
CONFIGURE_ARGS+=	--enable-cpu-level=6
CONFIGURE_ARGS+=	--enable-pci
CONFIGURE_ARGS+=	--enable-usb
CONFIGURE_ARGS+=	--enable-usb-ohci
CONFIGURE_ARGS+=	--enable-pnic
CONFIGURE_ARGS+=	--enable-repeat-speedups
CONFIGURE_ARGS+=	--enable-configurable-msrs
CONFIGURE_ARGS+=	--enable-all-optimizations
#CONFIGURE_ARGS+=	--enable-instrumentation
CONFIGURE_ARGS+=	--enable-clgd54xx
CONFIGURE_ARGS+=	--enable-fpu
CONFIGURE_ARGS+=	--enable-vmx=2
#CONFIGURE_ARGS+=	--enable-3dnow
CONFIGURE_ARGS+=	--enable-alignment-check
#CONFIGURE_ARGS+=	--enable-gdb-stub
CONFIGURE_ARGS+=	--enable-gameport

.  if empty(PKG_OPTIONS:Mdebug)
PLIST.plugins=		yes
CONFIGURE_ARGS+=	--enable-plugins
.  endif

.  if !empty(MACHINE_PLATFORM:M*-*-i386)
CONFIGURE_ARGS+=	--enable-fast-function-calls
.  endif

CONFIGURE_ARGS.Darwin+=		--enable-sb16=osx
CONFIGURE_ARGS.FreeBSD+=	--enable-sb16=freebsd
CONFIGURE_ARGS.Linux+=		--enable-sb16=linux
CONFIGURE_ARGS.Linux+=		--enable-pcidev
CONFIGURE_ARGS.*+=		--enable-sb16=dummy
.endif

.if empty(PKG_OPTIONS:Mx11)
PLIST.nox11=		yes
CONFIGURE_ARGS+=	--without-x
CONFIGURE_ARGS+=	--without-x11
CONFIGURE_ARGS+=	--with-term
.else
PLIST.x11=		yes
.endif

OPSYSVARS+=		BOCHSRC_SUBST
BOCHSRC_SUBST.Linux+=	-e 's,@FLOPPY_BSD@,\#,'
BOCHSRC_SUBST.Linux+=	-e 's,@FLOPPY_LINUX@,,'
BOCHSRC_SUBST.Darwin+=	-e 's,@FLOPPY_BSD@,\#,'
BOCHSRC_SUBST.Darwin+=	-e 's,@FLOPPY_LINUX@,\#,'
BOCHSRC_SUBST.*+=	-e 's,@FLOPPY_BSD@,,'
BOCHSRC_SUBST.*+=	-e 's,@FLOPPY_LINUX@,\#,'

.if ${OPSYS} == "Darwin"
MESSAGE_SRC=		${.CURDIR}/MESSAGE.Darwin
PLIST_SRC=		${.CURDIR}/PLIST.Darwin

post-build:
	{ ${ECHO} '#! ${SH}'; \
	  ${ECHO} 'exec ${PREFIX}/libexec/bochs.app/Contents/MacOS/bochs'\
	          '"$$@"'; } >${WRKDIR}/bochs.sh

post-install:
	/Developer/Tools/CpMac -r -p ${WRKSRC}/bochs.app ${PREFIX}/libexec
	${INSTALL_PROGRAM} ${WRKSRC}/bxcommit ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bximage ${PREFIX}/bin
	${RM} -rf ${PREFIX}/libexec/bochs.app/.build
	${INSTALL_SCRIPT} ${WRKDIR}/bochs.sh ${PREFIX}/bin/bochs
.else

.if !empty(PKG_OPTIONS:Mdebug) && !empty(PKG_OPTIONS:Mx11)
.include "../../x11/gtk2/buildlink3.mk"
.endif
.  if empty(PKG_OPTIONS:Mx11)
.  include "../../mk/curses.buildlink3.mk"
.  else
BUILDLINK_DEPMETHOD.libXt?=	build

.  include "../../x11/libSM/buildlink3.mk"
.  include "../../x11/libX11/buildlink3.mk"
.  include "../../x11/libXpm/buildlink3.mk"
.  include "../../x11/libXrandr/buildlink3.mk"
.  include "../../x11/libXt/buildlink3.mk"
.  endif
.endif

pre-configure:
	${SED} ${BOCHSRC_SUBST} <${WRKSRC}/.bochsrc >${WRKSRC}/.bochsrc.new
	mv ${WRKSRC}/.bochsrc.new ${WRKSRC}/.bochsrc

.include "../../mk/bsd.pkg.mk"
