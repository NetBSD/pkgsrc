# $NetBSD: Makefile,v 1.1 2020/03/31 10:03:35 nia Exp $

DISTNAME=	tl-expected-1.0.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=TartanLlama/}
GITHUB_PROJECT=	expected
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/TartanLlama/expected
COMMENT=	C++11/14/17 std::expected with functional-style extensions
LICENSE=	cc0-1.0-universal

USE_CMAKE=	yes
USE_LANGUAGES=	c c++

CMAKE_ARGS+=	-DEXPECTED_ENABLE_TESTS=OFF

.include "../../mk/bsd.pkg.mk"
