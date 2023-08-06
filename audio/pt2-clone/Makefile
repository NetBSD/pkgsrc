# $NetBSD: Makefile,v 1.20 2023/08/06 09:49:27 nia Exp $

DISTNAME=	pt2-clone-1.49
PKGREVISION=	3
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GITHUB:=8bitbubsy/}
GITHUB_PROJECT=	pt2-clone
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/8bitbubsy/pt2-clone/
COMMENT=	ProTracker 2 clone
LICENSE=	modified-bsd

USE_CMAKE=	yes

USE_LANGUAGES=	c c++

# error: 'for' loop initial declarations are only allowed in C99 mode
# gnu99 needed to get PATH_MAX definition on certain platforms
FORCE_C_STD=	gnu99

INSTALLATION_DIRS+=	share/applications
INSTALLATION_DIRS+=	share/doc/${PKGBASE}
INSTALLATION_DIRS+=	share/examples/${PKGBASE}
INSTALLATION_DIRS+=	share/pixmaps
INSTALLATION_DIRS+=	${PKGMANDIR}/man1

post-install:
	cd ${WRKSRC} && ${INSTALL_DATA} release/other/protracker.ini \
		${DESTDIR}${PREFIX}/share/examples/pt2-clone/protracker.ini
	cd ${WRKSRC}/release && ${INSTALL_DATA} *.txt \
		${DESTDIR}${PREFIX}/share/doc/${PKGBASE}
	cd ${WRKSRC}/release/other && ${INSTALL_DATA} \
		Freedesktop.org\ Resources/ProTracker\ 2\ clone.desktop \
		${DESTDIR}${PREFIX}/share/applications/${PKGBASE}.desktop
	cd ${FILESDIR} && ${INSTALL_DATA} pt2-clone.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/${PKGBASE}.1
	cd ${WRKSRC}/release/other && ${INSTALL_DATA} \
		Freedesktop.org\ Resources/ProTracker\ 2\ clone.png \
		${DESTDIR}${PREFIX}/share/pixmaps

.include "../../devel/SDL2/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
