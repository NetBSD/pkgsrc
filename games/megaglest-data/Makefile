# $NetBSD: Makefile,v 1.2 2025/08/20 11:34:57 wiz Exp $

DISTNAME=	megaglest-data-3.13.0
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=MegaGlest/}
GITHUB_PROJECT=	megaglest-data
GITHUB_RELEASE=	${PKGVERSION_NOREV}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://megaglest.org/
COMMENT=	3D real-time-strategy game with seven factions (data files)
LICENSE=	cc-by-sa-v3.0

EXTRACT_USING=	bsdtar
WRKSRC=		${WRKDIR}/megaglest-${PKGVERSION_NOREV}
USE_CMAKE=	yes
# XXX only needed because cmake complains otherwise
USE_LANGUAGES=	c c++

CMAKE_CONFIGURE_ARGS+=  -DCMAKE_POLICY_VERSION_MINIMUM=3.5

.include "../../mk/bsd.pkg.mk"
