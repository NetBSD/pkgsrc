# $NetBSD: Makefile,v 1.1 2019/06/30 20:53:09 nia Exp $

DISTNAME=	redeclipse_1.6.0_nix
PKGNAME=	redeclipse-1.6.0
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=red-eclipse/}
EXTRACT_SUFX=	.tar.bz2
GITHUB_PROJECT=	base
GITHUB_RELEASE=	v${PKGVERSION_NOREV}

MAINTAINER=	cfkoch@edgebsd.org
HOMEPAGE=	https://redeclipse.net/
COMMENT=	Free casual arena shooter
LICENSE=	zlib AND cc-by-sa-v3.0

WRKSRC=		${WRKDIR}/redeclipse-${PKGVERSION_NOREV}

NO_CONFIGURE=	yes
USE_TOOLS+=	gmake
USE_LANGUAGES+=	c c++

BUILD_DIRS=	src
INSTALL_TARGET=	system-install

MAKE_FLAGS+=	prefix=${PREFIX}
MAKE_FLAGS+=	mandir=${DESTDIR}${PREFIX}/${PKGMANDIR}

.include "../../devel/SDL2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../audio/SDL2_mixer/buildlink3.mk"
.include "../../graphics/SDL2_image/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
