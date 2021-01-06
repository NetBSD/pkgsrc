# $NetBSD: Makefile,v 1.1 2021/01/06 00:52:22 js Exp $

DISTNAME=	pt2-clone-1.28
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GITHUB:=8bitbubsy/}
GITHUB_PROJECT=	pt2-clone
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	js@pkgsrc.org
HOMEPAGE=	https://github.com/8bitbubsy/pt2-clone/
COMMENT=	ProTracker 2 clone for Windows/macOS/Linux
LICENSE=	modified-bsd

WRKSRC=		${WRKDIR}/pt2-clone-1.28

INSTALLATION_DIRS+=	bin share/examples/pt2-clone

do-build:
	cd ${WRKSRC} && ${CC} -o pt2-clone \
		-O2 -DNDEBUG \
		$$(sdl2-config --cflags --libs) \
		src/*.c src/gfx/*.c

do-install:
	cd ${WRKSRC} && ${INSTALL} -m 755 pt2-clone \
		${DESTDIR}${PREFIX}/bin/pt2-clone
	cd ${WRKSRC} && ${INSTALL} -m 644 release/other/protracker.ini \
		${DESTDIR}${PREFIX}/share/examples/pt2-clone/protracker.ini

.include "../../devel/SDL2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
