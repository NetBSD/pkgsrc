# $NetBSD: Makefile,v 1.1 2023/04/28 08:53:46 nikita Exp $

DISTNAME=	cppcodec-0.2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=tplgy/}
GITHUB_PROJECT=	cppcodec
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/tplgy/cppcodec/
COMMENT=	C++11 library to encode/decode various codes
LICENSE=	mit

USE_LANGUAGES=	c c++11


.include "../../devel/catch2/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
