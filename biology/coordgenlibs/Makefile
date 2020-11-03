# $NetBSD: Makefile,v 1.1 2020/11/03 20:17:59 bsiegert Exp $

GITHUB_TAG=	v${PKGVERSION_NOREV}
DISTNAME=	coordgenlibs-1.4.2
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
