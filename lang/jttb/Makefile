# $NetBSD: Makefile,v 1.2 2024/10/13 09:02:36 wiz Exp $

DISTNAME=	JTTB-0.5.1
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

.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
