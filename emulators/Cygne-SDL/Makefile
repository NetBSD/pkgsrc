# $NetBSD: Makefile,v 1.7 2005/06/16 06:57:50 jlam Exp $
#

DISTNAME=		Cygne-SDL-0.1-src
PKGNAME=		${DISTNAME:S/-src//}
PKGREVISION=	2
CATEGORIES=		emulators
MASTER_SITES=		http://sdlemu.ngemu.com/OpenProjects/

MAINTAINER=		wiz@NetBSD.org
HOMEPAGE=		http://icculus.org/Cygne-SDL/
COMMENT=		Bandai Wonderswan Color handheld emulator

BUILD_DEPENDS+=		nasm>=0.98:../../devel/nasm
BUILD_DEPENDS+=		zip>=2.0:../../archivers/zip

WRKSRC=			${WRKDIR}/Cygne-SDL-0.1/src
MAKEFILE=		Makefiles/Makefile.unix
NO_CONFIGURE=		yes
USE_LANGUAGES=		c c++

# Uses i386 assembly code
ONLY_FOR_PLATFORM=	*-*-i386

INSTALLATION_DIRS=	bin

post-build:
	cd ${WRKSRC}/../WonderSnake && \
		${LOCALBASE}/bin/zip Wondersnake.zip Wondersnake.wsc

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cygne ${PREFIX}/bin/Cygne-SDL
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/Cygne-SDL
	${INSTALL_DATA} ${WRKSRC}/../README ${PREFIX}/share/doc/Cygne-SDL
	${INSTALL_DATA_DIR} ${PREFIX}/share/Cygne-SDL
	${INSTALL_DATA} ${WRKSRC}/../WonderSnake/Wondersnake.txt \
		${PREFIX}/share/Cygne-SDL
	${INSTALL_DATA} ${WRKSRC}/../WonderSnake/Wondersnake.zip \
		${PREFIX}/share/Cygne-SDL

.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
