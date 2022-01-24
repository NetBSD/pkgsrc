# $NetBSD: Makefile,v 1.11 2022/01/24 14:01:01 nia Exp $

DISTNAME=	pt2-clone-1.39
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GITHUB:=8bitbubsy/}
GITHUB_PROJECT=	pt2-clone
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/8bitbubsy/pt2-clone/
COMMENT=	ProTracker 2 clone
LICENSE=	modified-bsd

TOOL_DEPENDS+=	icoutils-[0-9]*:../../graphics/icoutils

USE_CMAKE=	yes

# error: 'for' loop initial declarations are only allowed in C99 mode
USE_LANGUAGES=	c99 c++

INSTALLATION_DIRS+=	share/applications
INSTALLATION_DIRS+=	share/examples/pt2-clone
INSTALLATION_DIRS+=	share/pixmaps
INSTALLATION_DIRS+=	${PKGMANDIR}/man1

post-build:
	icotool -w 48 -x -o ${WRKDIR}/${PKGBASE}.png \
		${WRKSRC}/src/gfx/pt2-clone.ico

post-install:
	cd ${WRKSRC} && ${INSTALL_DATA} release/other/protracker.ini \
		${DESTDIR}${PREFIX}/share/examples/pt2-clone/protracker.ini
	cd ${FILESDIR} && ${INSTALL_DATA} pt2-clone.desktop \
		${DESTDIR}${PREFIX}/share/applications/${PKGBASE}.desktop
	cd ${FILESDIR} && ${INSTALL_DATA} pt2-clone.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/${PKGBASE}.1
	${INSTALL_DATA} ${WRKDIR}/${PKGBASE}.png \
		${DESTDIR}${PREFIX}/share/pixmaps/${PKGBASE}.png

.include "../../devel/SDL2/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
