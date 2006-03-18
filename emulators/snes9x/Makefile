# $NetBSD: Makefile,v 1.35 2006/03/18 15:56:00 ben Exp $

SNESVER=		1.43
DISTNAME=		snes9x-${SNESVER}-src
PKGNAME=		snes9x-${SNESVER}
CATEGORIES=		emulators
MASTER_SITES=		http://www.lysator.liu.se/snes9x/${SNESVER}/ \
			http://files.ipherswipsite.com/snes9x/ \
			http://vincent.grigorieff.free.fr/snes9x/

MAINTAINER=		ben@NetBSD.org
HOMEPAGE=		http://www.snes9x.com/
COMMENT=		Super Nintendo Entertainment System (SNES) emulator

WRKSRC=			${WRKDIR}/${DISTNAME}/snes9x
USE_TOOLS+=		gmake
PTHREAD_OPTS+=		require
INSTALLATION_DIRS=	bin
GNU_CONFIGURE=		YES

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/snes9x ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/offsets ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/snes9x
	${INSTALL_MAN} ${WRKSRC}/doc/porting.txt ${PREFIX}/share/doc/snes9x
	${INSTALL_MAN} ${WRKSRC}/changes.txt ${PREFIX}/share/doc/snes9x
	${INSTALL_MAN} ${WRKSRC}/hardware.txt ${PREFIX}/share/doc/snes9x
	${INSTALL_MAN} ${WRKSRC}/problems.txt ${PREFIX}/share/doc/snes9x
	${TR} -d '\r' <${WRKDIR}/${DISTNAME}/readme.txt >${WRKSRC}/readme.txt
	${INSTALL_MAN} ${WRKSRC}/readme.txt ${PREFIX}/share/doc/snes9x
	${INSTALL_MAN} ${WRKDIR}/${DISTNAME}/readme.unix \
		${PREFIX}/share/doc/snes9x

.include "../../mk/bsd.prefs.mk"

PKG_OPTIONS_VAR=	PKG_OPTIONS.snes9x
.if ${MACHINE_ARCH} == "i386"
BUILD_DEPENDS+=		nasm>=0.98:../../devel/nasm
PKG_SUPPORTED_OPTIONS=	mmx
.endif

.include "../../mk/bsd.options.mk"

.if ${MACHINE_ARCH} == "i386"
CONFIGURE_ARGS+=	--with-assembler
.if !empty(PKG_OPTIONS:Mmmx)
CONFIGURE_ARGS+=	--with-mmx
.endif
.if ${OBJECT_FMT} == "a.out"
MAKE_ENV+=	FILEFORMAT=aoutb
MAKE_ENV+=	_ASM_UNDERBARS=1
.else
MAKE_ENV+=	FILEFORMAT=elf
.endif
.endif

.if exists(${X11BASE}/lib/libXxf86dga.a)
CONFIGURE_ARGS+=	--with-extensions
.endif

.if exists(/usr/include/usb.h) || exists(/usr/include/usbhid.h)
MAKE_ENV+=	USBJOY=1
.if exists(/usr/include/usbhid.h)
MAKE_ENV+=	USBHID_H=1
.endif
.endif

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
