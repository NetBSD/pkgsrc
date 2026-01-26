# $NetBSD: Makefile,v 1.1 2026/01/26 19:43:32 nia Exp $

DISTNAME=	jstrings-1.6
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=drojaazu/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/drojaazu/jstrings
COMMENT=	Tool for finding Shift JIS in binary data
LICENSE=	mit

USE_LANGUAGES=	c c++

USE_CXX_FEATURES=	c++17

.include "../../devel/cmake/build.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
