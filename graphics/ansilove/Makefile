# $NetBSD: Makefile,v 1.26 2025/03/31 06:06:24 adam Exp $

DISTNAME=	ansilove-4.2.1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=ansilove/}
GITHUB_RELEASE=	${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.ansilove.org/
COMMENT=	ANSI and ASCII art to PNG converter
LICENSE=	2-clause-bsd

USE_CC_FEATURES=	c99
USE_LANGUAGES=		c
TEST_TARGET=		test

.include "../../devel/cmake/build.mk"
.include "../../graphics/libansilove/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
