# $NetBSD: Makefile,v 1.122 2026/01/27 08:39:23 wiz Exp $

DISTNAME=		bochs-2.7
PKGREVISION=		12
CATEGORIES=		emulators
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=bochs/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://bochs.sourceforge.net/
COMMENT=		IA32 and AMD64 PC emulator
LICENSE=		gnu-lgpl-v2.1

MAKE_JOBS_SAFE=		no

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake gunzip gzip
USE_LANGUAGES=		c c++
FORCE_CXX_STD=		c++11
USE_LIBTOOL=		yes

CXXFLAGS+=		-DPARANOID

CONFIGURE_ARGS+=	--disable-docbook
CONFIGURE_ARGS+=	--enable-cdrom
CONFIGURE_ARGS+=	--enable-ne2000

MAKE_ENV+=		GZIP_CMD=${GZIP_CMD:Q}
MAKE_ENV+=		GUNZIP_CMD=${GUNZIP_CMD:Q}
MAKE_ENV+=		WGET=${FETCH_CMD:Q}

.include "../../mk/bsd.prefs.mk"

CONFIGURE_ARGS+=	--enable-idle-hack
CONFIGURE_ARGS+=	--enable-a20-pin
CONFIGURE_ARGS+=	--enable-x86-64
CONFIGURE_ARGS+=	--enable-smp
CONFIGURE_ARGS+=	--enable-long-phy-address
CONFIGURE_ARGS+=	--enable-cpu-level=6
CONFIGURE_ARGS+=	--enable-pci
CONFIGURE_ARGS+=	--enable-usb
CONFIGURE_ARGS+=	--enable-usb-ohci
CONFIGURE_ARGS+=	--enable-usb-ehci
CONFIGURE_ARGS+=	--enable-usb-xhci
CONFIGURE_ARGS+=	--enable-pnic
CONFIGURE_ARGS+=	--enable-repeat-speedups
CONFIGURE_ARGS+=	--enable-configurable-msrs
CONFIGURE_ARGS+=	--enable-all-optimizations
#CONFIGURE_ARGS+=	--enable-instrumentation
CONFIGURE_ARGS+=	--enable-clgd54xx
CONFIGURE_ARGS+=	--enable-e1000
CONFIGURE_ARGS+=	--enable-voodoo
CONFIGURE_ARGS+=	--enable-fpu
CONFIGURE_ARGS+=	--enable-vmx=2
CONFIGURE_ARGS+=	--enable-svm
CONFIGURE_ARGS+=	--enable-3dnow
CONFIGURE_ARGS+=	--enable-avx
CONFIGURE_ARGS+=	--enable-evex
CONFIGURE_ARGS+=	--enable-alignment-check
#CONFIGURE_ARGS+=	--enable-gdb-stub
CONFIGURE_ARGS+=	--enable-gameport
CONFIGURE_ARGS+=	--enable-busmouse

.if !empty(MACHINE_PLATFORM:M*-*-i386)
CONFIGURE_ARGS+=	--enable-fast-function-calls
.endif

CONFIGURE_ARGS.Linux+=		--enable-pcidev
CONFIGURE_ARGS+=		--enable-sb16
CONFIGURE_ARGS+=		--enable-es1370

.if ${OPSYS} == "Linux"
SUBST_CLASSES+=		nobpf
SUBST_FILES.nobpf=	config.h
SUBST_SED.nobpf=	-e 's:BX_NETMOD_FBSD 1:BX_NETMOD_FBSD 0:'
SUBST_STAGE.nobpf=	post-configure
SUBST_NOOP_OK.nobpf=	yes
.endif

OPSYSVARS+=		BOCHSRC_SUBST
BOCHSRC_SUBST.Linux+=	-e 's,@FLOPPY_BSD@,\#,'
BOCHSRC_SUBST.Linux+=	-e 's,@FLOPPY_LINUX@,,'
BOCHSRC_SUBST.Darwin+=	-e 's,@FLOPPY_BSD@,\#,'
BOCHSRC_SUBST.Darwin+=	-e 's,@FLOPPY_LINUX@,\#,'
BOCHSRC_SUBST.*+=	-e 's,@FLOPPY_BSD@,,'
BOCHSRC_SUBST.*+=	-e 's,@FLOPPY_LINUX@,\#,'

PRINT_PLIST_AWK+=	/\/plugins\// { $$0 = "$${PLIST.plugins}" $$0 }
PRINT_PLIST_AWK+=	/libbx_/ { $$0 = "$${PLIST.notiny}" $$0 }

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
.endif

pre-configure:
	${SED} ${BOCHSRC_SUBST} <${WRKSRC}/.bochsrc >${WRKSRC}/.bochsrc.new
	mv ${WRKSRC}/.bochsrc.new ${WRKSRC}/.bochsrc

.include "options.mk"
.include "../../mk/bsd.pkg.mk"
