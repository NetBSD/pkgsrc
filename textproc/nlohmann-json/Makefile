# $NetBSD: Makefile,v 1.3 2024/06/17 09:32:13 wiz Exp $

DISTNAME=	nlohmann-json-3.11.3
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=nlohmann/}
GITHUB_PROJECT=	json
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://json.nlohmann.me/
COMMENT=	JSON library for Modern C++
LICENSE=	mit

USE_LANGUAGES=	c c++

.include "options.mk"
.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
