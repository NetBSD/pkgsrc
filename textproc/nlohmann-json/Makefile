# $NetBSD: Makefile,v 1.2 2023/11/21 17:37:52 nia Exp $

DISTNAME=	nlohmann-json-3.11.2
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=nlohmann/}
GITHUB_PROJECT=	json
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://json.nlohmann.me/
COMMENT=	JSON library for Modern C++
LICENSE=	mit

USE_LANGUAGES=	c c++11

.include "options.mk"
.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
