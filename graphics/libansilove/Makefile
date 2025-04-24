# $NetBSD: Makefile,v 1.31 2025/04/24 14:14:28 wiz Exp $

DISTNAME=	libansilove-1.4.2
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=ansilove/}
GITHUB_RELEASE=	${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.ansilove.org/
COMMENT=	Library for converting ANSI, ASCII, and other formats to PNG
LICENSE=	2-clause-bsd

USE_CC_FEATURES=	c99
USE_LANGUAGES=		c

.include "../../devel/cmake/build.mk"
.include "../../graphics/gd/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
