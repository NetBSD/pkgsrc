# $NetBSD: Makefile,v 1.25 2012/10/03 12:55:20 asau Exp $

DISTNAME=		VisualBoyAdvance-src-1.7.2
PKGNAME=		vba-1.7.2
PKGREVISION=		5
CATEGORIES=		emulators
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=vba/}

MAINTAINER=		dillo@NetBSD.org
HOMEPAGE=		http://vba.ngemu.com/
COMMENT=		Gameboy advance emulator

WRKSRC=			${WRKDIR}/VisualBoyAdvance-1.7.2
USE_TOOLS+=		gmake
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
#CONFIGURE_ARGS+=	--enable-c-core
#CONFIGURE_ARGS+=	--without-mmx
USE_LANGUAGES=		c c++
UNLIMIT_RESOURCES=	datasize

GCC_REQD+=		3.0.0
INSTALLATION_DIRS=	bin

.if ${MACHINE_ARCH} == "i386"
BUILD_DEPENDS+=		nasm-[0-9]*:../../devel/nasm
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/sdl/TestEmu ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/src/sdl/VisualBoyAdvance \
		${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/vba
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/vba

.include "../../devel/SDL/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
