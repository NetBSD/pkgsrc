# $NetBSD: Makefile,v 1.4 2021/09/29 19:00:03 adam Exp $

GITHUB_TAG=	v${PKGVERSION_NOREV}
DISTNAME=	maeparser-1.2.4
PKGREVISION=	3
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
