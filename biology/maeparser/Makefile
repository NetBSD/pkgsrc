# $NetBSD: Makefile,v 1.12 2025/09/27 09:57:07 wiz Exp $

GITHUB_TAG=	v${PKGVERSION_NOREV}
DISTNAME=	maeparser-1.3.2
PKGREVISION=	1
CATEGORIES=	biology
MASTER_SITES=	${MASTER_SITE_GITHUB:=schrodinger/}

MAINTAINER=	bsiegert@NetBSD.org
HOMEPAGE=	https://github.com/schrodinger/maeparser/
COMMENT=	Parser for Maestro file format
LICENSE=	mit

USE_LANGUAGES=	c c++

.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
