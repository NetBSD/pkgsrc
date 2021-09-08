# $NetBSD: Makefile,v 1.7 2021/09/08 21:04:57 nia Exp $

DISTNAME=	pt2-clone-1.28
PKGREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GITHUB:=8bitbubsy/}
GITHUB_PROJECT=	pt2-clone
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/8bitbubsy/pt2-clone/
COMMENT=	ProTracker 2 clone
LICENSE=	modified-bsd

USE_CMAKE=	yes

# error: 'for' loop initial declarations are only allowed in C99 mode
USE_LANGUAGES=	c99 c++

INSTALLATION_DIRS+=	share/examples/pt2-clone

post-install:
	cd ${WRKSRC} && ${INSTALL_DATA} release/other/protracker.ini \
		${DESTDIR}${PREFIX}/share/examples/pt2-clone/protracker.ini

.include "../../devel/SDL2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
