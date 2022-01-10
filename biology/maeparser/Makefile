# $NetBSD: Makefile,v 1.5 2022/01/10 01:46:22 ryoon Exp $

GITHUB_TAG=	v${PKGVERSION_NOREV}
DISTNAME=	maeparser-1.2.4
PKGREVISION=	4
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
