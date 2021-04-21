# $NetBSD: Makefile,v 1.3 2021/04/21 13:24:07 adam Exp $

GITHUB_TAG=	v${PKGVERSION_NOREV}
DISTNAME=	maeparser-1.2.4
PKGREVISION=	2
CATEGORIES=	biology
MASTER_SITES=	${MASTER_SITE_GITHUB:=schrodinger/}

MAINTAINER=	bsiegert@NetBSD.org
HOMEPAGE=	https://github.com/schrodinger/maeparser/
COMMENT=	Parser for Maestro file format
LICENSE=	mit

USE_CMAKE=	yes
USE_LANGUAGES=	c c++


.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
