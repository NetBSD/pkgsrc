# $NetBSD: Makefile,v 1.9 2022/08/11 05:08:35 gutteridge Exp $

DISTNAME=	sdlpop-1.22
PKGREVISION=	4
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=NagyD/}
GITHUB_PROJECT=	SDLPoP
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/NagyD/SDLPoP
COMMENT=	Open-source port of Prince of Persia
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake pkg-config

BUILD_DIRS=	src

MAKE_FLAGS=	CC=${CC:Q}

CFLAGS+=	-DPKGSRC_DATA_PATH="\"${PREFIX}/share/sdlpop/\""

INSTALLATION_DIRS+=	bin
INSTALLATION_DIRS+=	share/applications
INSTALLATION_DIRS+=	share/doc/sdlpop
INSTALLATION_DIRS+=	share/pixmaps
INSTALLATION_DIRS+=	share/sdlpop

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/prince ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/SDLPoP.ini ${DESTDIR}${PREFIX}/share/sdlpop
	${INSTALL_DATA} ${WRKSRC}/doc/ChangeLog.txt ${DESTDIR}${PREFIX}/share/doc/sdlpop
	${INSTALL_DATA} ${WRKSRC}/doc/Readme.txt ${DESTDIR}${PREFIX}/share/doc/sdlpop
	cd ${WRKSRC} && find data -type d | while read dir; do \
		${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/sdlpop/$$dir; \
	done
	cd ${WRKSRC} && find data -type f | while read file; do \
		${INSTALL_DATA} $$file ${DESTDIR}${PREFIX}/share/sdlpop/$$file; \
	done
	${INSTALL_DATA} ${FILESDIR}/prince.desktop ${DESTDIR}${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/data/icon.png ${DESTDIR}${PREFIX}/share/pixmaps/prince.png

.include "../../audio/SDL2_mixer/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../graphics/SDL2_image/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
