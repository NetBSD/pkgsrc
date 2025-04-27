# $NetBSD: Makefile,v 1.5 2025/04/27 20:07:25 wiz Exp $

DISTNAME=	nlohmann-json-3.12.0
PKGREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=nlohmann/}
GITHUB_PROJECT=	json
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://json.nlohmann.me/
COMMENT=	JSON library for Modern C++
LICENSE=	mit

USE_LANGUAGES=	c c++

post-install:
	${RM} ${DESTDIR}${PREFIX}/include/nlohmann/detail/conversions/*.orig

.include "options.mk"
.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
