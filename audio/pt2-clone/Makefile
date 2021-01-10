# $NetBSD: Makefile,v 1.3 2021/01/10 11:31:32 nia Exp $

DISTNAME=	pt2-clone-1.28
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GITHUB:=8bitbubsy/}
GITHUB_PROJECT=	pt2-clone
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	js@pkgsrc.org
HOMEPAGE=	https://github.com/8bitbubsy/pt2-clone/
COMMENT=	ProTracker 2 clone for Windows/macOS/Linux
LICENSE=	modified-bsd

USE_CMAKE=	yes
USE_LANGUAGES=	c c++

INSTALLATION_DIRS+=	share/examples/pt2-clone

post-install:
	cd ${WRKSRC} && ${INSTALL_DATA} release/other/protracker.ini \
		${DESTDIR}${PREFIX}/share/examples/pt2-clone/protracker.ini

.include "../../devel/SDL2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
