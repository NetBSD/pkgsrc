# $NetBSD: Makefile,v 1.24 2023/04/01 09:50:58 fcambus Exp $

DISTNAME=	ansilove-4.1.7
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=ansilove/}
GITHUB_RELEASE=	${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.ansilove.org/
COMMENT=	ANSI and ASCII art to PNG converter
LICENSE=	2-clause-bsd

USE_LANGUAGES=	c99
USE_CMAKE=	yes

TEST_TARGET=	test

.include "../../graphics/libansilove/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
