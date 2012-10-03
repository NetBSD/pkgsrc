# $NetBSD: Makefile,v 1.49 2012/10/03 12:55:18 asau Exp $

SNESVER=		1.43
DISTNAME=		snes9x-${SNESVER}-src
PKGNAME=		snes9x-${SNESVER}
CATEGORIES=		emulators
MASTER_SITES=		http://www.lysator.liu.se/snes9x/${SNESVER}/ \
			http://files.ipherswipsite.com/snes9x/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.snes9x.com/
COMMENT=		Super Nintendo Entertainment System (SNES) emulator

NOT_FOR_PLATFORM=	${LP64PLATFORMS}
MAKE_JOBS_SAFE=		no

WRKSRC=			${WRKDIR}/${DISTNAME}/snes9x
USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake
PTHREAD_OPTS+=		require
INSTALLATION_DIRS=	bin
GNU_CONFIGURE=		YES

SUBST_CLASSES+=		nodos
SUBST_STAGE.nodos=	pre-patch
SUBST_FILES.nodos=	../language.h
SUBST_FILES.nodos+=	../readme.txt dsp1.h dsp3emu.cpp dsp4emu.cpp
SUBST_FILTER_CMD.nodos=	env -i ${TR} -d '\r'

SUBST_CLASSES+=		paircpp
SUBST_STAGE.paircpp=	pre-patch
SUBST_FILES.paircpp=	65c816.h sa1.h
SUBST_SED.paircpp=	-e 's|pair|snes9x_pair|g'

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/snes9x ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/offsets ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/snes9x
	${INSTALL_MAN} ${WRKSRC}/doc/porting.txt \
		${DESTDIR}${PREFIX}/share/doc/snes9x
	${INSTALL_MAN} ${WRKSRC}/changes.txt \
		${DESTDIR}${PREFIX}/share/doc/snes9x
	${INSTALL_MAN} ${WRKSRC}/hardware.txt \
		${DESTDIR}${PREFIX}/share/doc/snes9x
	${INSTALL_MAN} ${WRKSRC}/problems.txt \
		${DESTDIR}${PREFIX}/share/doc/snes9x
	${INSTALL_MAN} ${WRKDIR}/${DISTNAME}/readme.txt \
		${DESTDIR}${PREFIX}/share/doc/snes9x
	${INSTALL_MAN} ${WRKDIR}/${DISTNAME}/readme.unix \
		${DESTDIR}${PREFIX}/share/doc/snes9x

.include "../../mk/bsd.prefs.mk"

PKG_OPTIONS_VAR=	PKG_OPTIONS.snes9x
PKG_SUPPORTED_OPTIONS=	# empty
.if ${MACHINE_ARCH} == "i386"
BUILD_DEPENDS+=		nasm>=0.98:../../devel/nasm
PKG_SUPPORTED_OPTIONS+=	mmx
.endif

.include "../../mk/bsd.options.mk"

.if ${MACHINE_ARCH} == "i386"
CONFIGURE_ARGS+=	--with-assembler
.  if !empty(PKG_OPTIONS:Mmmx)
CONFIGURE_ARGS+=	--with-mmx
.  endif
.  if ${OBJECT_FMT} == "a.out"
MAKE_ENV+=	FILEFORMAT=aoutb
MAKE_ENV+=	_ASM_UNDERBARS=1
.  else
MAKE_ENV+=	FILEFORMAT=elf
.  endif
.endif

.if exists(${X11BASE}/lib/libXxf86dga.a) || ${X11_TYPE} != "native"
CONFIGURE_ARGS+=	--with-extensions
.endif

.if exists(/usr/include/usb.h) || exists(/usr/include/usbhid.h)
MAKE_ENV+=	USBJOY=1
.  if exists(/usr/include/usbhid.h)
MAKE_ENV+=	USBHID_H=1
.  endif
.endif

BUILDLINK_DEPMETHOD.libXt?=	build

.include "../../devel/zlib/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXxf86dga/buildlink3.mk"
.include "../../x11/libXxf86vm/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
