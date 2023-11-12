# $NetBSD: Makefile,v 1.3 2023/11/12 13:21:43 wiz Exp $

DISTNAME=	redeclipse_1.6.0_nix
PKGNAME=	redeclipse16-1.6.0
PKGREVISION=	2
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=redeclipse/}
GITHUB_PROJECT=	base
GITHUB_RELEASE=	v${PKGVERSION_NOREV}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	charlotte@NetBSD.org
HOMEPAGE=	https://redeclipse.net/
COMMENT=	Free casual arena shooter (older version)
LICENSE=	zlib AND cc-by-sa-v3.0

WRKSRC=		${WRKDIR}/redeclipse-${PKGVERSION_NOREV}

TOOL_DEPENDS+=	ed>0:../../editors/ed

NO_CONFIGURE=	yes
USE_TOOLS+=	gmake pkg-config
USE_LANGUAGES+=	c c++

BUILD_DIRS=	src
INSTALL_TARGET=	system-install

MAKE_FLAGS+=	APPNAME=${PKGBASE}
MAKE_FLAGS+=	appsrcname=redeclipse
MAKE_FLAGS+=	prefix=${PREFIX}
MAKE_FLAGS+=	mandir=${DESTDIR}${PREFIX}/${PKGMANDIR}
MAKE_FLAGS+=	ED=ged

# GCC precompiled headers...
RELRO_SUPPORTED=	no

.include "../../devel/SDL2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../audio/SDL2_mixer/buildlink3.mk"
.include "../../graphics/SDL2_image/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
