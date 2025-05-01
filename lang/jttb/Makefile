# $NetBSD: Makefile,v 1.4 2025/05/01 00:55:34 thorpej Exp $

DISTNAME=	JTTB-0.6
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GITHUB:=thorpej/}
GITHUB_PROJECT=	JTTB
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	thorpej@NetBSD.org
HOMEPAGE=	https://github.com/thorpej/JTTB
COMMENT=	Small, portable BASIC interpreter written in C
LICENSE=	2-clause-bsd

USE_LANGUAGES=	c c++

CFLAGS+=	-Wno-error=unknown-pragmas

MAKE_JOBS_SAFE=	no

.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
