# $NetBSD: Makefile,v 1.14 2026/08/24 08:42:11 adam Exp $

GITHUB_TAG=	v${PKGVERSION_NOREV}
DISTNAME=	coordgenlibs-1.4.2
PKGREVISION=	12
CATEGORIES=	biology
MASTER_SITES=	${MASTER_SITE_GITHUB:=schrodinger/}

MAINTAINER=	bsiegert@NetBSD.org
HOMEPAGE=	https://github.com/schrodinger/coordgenlibs/
COMMENT=	2D coordinate generation for molecules
LICENSE=	modified-bsd

USE_CMAKE=	yes
USE_LANGUAGES=	c c++

CMAKE_CONFIGURE_ARGS+=	-DCMAKE_POLICY_VERSION_MINIMUM=3.5

.include "../../biology/maeparser/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
