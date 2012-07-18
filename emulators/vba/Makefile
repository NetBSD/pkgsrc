# $NetBSD: Makefile,v 1.24 2012/07/18 21:55:40 marino Exp $

DISTNAME=		VisualBoyAdvance-src-1.7.2
PKGNAME=		vba-1.7.2
PKGREVISION=		5
CATEGORIES=		emulators
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=vba/}

MAINTAINER=		dillo@NetBSD.org
HOMEPAGE=		http://vba.ngemu.com/
COMMENT=		Gameboy advance emulator

PKG_DESTDIR_SUPPORT=	user-destdir

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
