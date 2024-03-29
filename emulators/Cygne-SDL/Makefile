# $NetBSD: Makefile,v 1.22 2023/06/06 12:41:20 riastradh Exp $
#

DISTNAME=		Cygne-SDL-0.1-src
PKGNAME=		${DISTNAME:S/-src//}
PKGREVISION=		7
CATEGORIES=		emulators
MASTER_SITES=		http://sdlemu.ngemu.com/OpenProjects/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://icculus.org/Cygne-SDL/
COMMENT=		Bandai Wonderswan Color handheld emulator

# The makefile mentions nasm but does not actually use it.
#TOOL_DEPENDS+=	nasm>=0.98:../../devel/nasm

WRKSRC=			${WRKDIR}/Cygne-SDL-0.1
MAKE_FILE=		Makefiles/Makefile.unix
NO_CONFIGURE=		yes
BUILD_DIRS=		src
USE_LANGUAGES=		c c++
USE_TOOLS+=		zip

INSTALLATION_DIRS=	bin share/Cygne-SDL share/doc/Cygne-SDL

post-build:
	cd ${WRKSRC}/WonderSnake && \
		${TOOLS_PATH.zip} Wondersnake.zip Wondersnake.wsc

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/cygne ${DESTDIR}${PREFIX}/bin/Cygne-SDL
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/Cygne-SDL
	${INSTALL_DATA} ${WRKSRC}/WonderSnake/Wondersnake.txt \
		${DESTDIR}${PREFIX}/share/Cygne-SDL
	${INSTALL_DATA} ${WRKSRC}/WonderSnake/Wondersnake.zip \
		${DESTDIR}${PREFIX}/share/Cygne-SDL

.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
