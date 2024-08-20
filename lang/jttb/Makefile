# $NetBSD: Makefile,v 1.1 2024/08/20 14:18:12 thorpej Exp $

JTTB_VERSION=	0.5.1

GITHUB_PROJECT=	JTTB
GITHUB_TAG=	${JTTB_VERSION}

DISTNAME=	${GITHUB_PROJECT}-${GITHUB_TAG}
PKGNAME=	${GITHUB_PROJECT}-${JTTB_VERSION}
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GITHUB:=thorpej/}

MAINTAINER=	thorpej@NetBSD.org
HOMEPAGE=	https://github.com/thorpej/JTTB
COMMENT=	A small, portable BASIC interpreter written in C
LICENSE=	2-clause-bsd

USE_LANGUAGES=	c c++

CFLAGS+=	-Wno-error=unknown-pragmas

.include "../../mk/bsd.prefs.mk"

.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
