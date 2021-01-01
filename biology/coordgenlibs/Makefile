# $NetBSD: Makefile,v 1.2 2021/01/01 08:24:34 ryoon Exp $

GITHUB_TAG=	v${PKGVERSION_NOREV}
DISTNAME=	coordgenlibs-1.4.2
PKGREVISION=	1
CATEGORIES=	biology
MASTER_SITES=	${MASTER_SITE_GITHUB:=schrodinger/}

MAINTAINER=	bsiegert@NetBSD.org
HOMEPAGE=	https://github.com/schrodinger/coordgenlibs/
COMMENT=	2D coordinate generation for molecules
LICENSE=	modified-bsd

USE_CMAKE=	yes
USE_LANGUAGES=	c c++


.include "../../biology/maeparser/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
