# $NetBSD: Makefile,v 1.5 2020/01/01 23:02:59 fcambus Exp $

DISTNAME=	libansilove-1.1.7
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=ansilove/}
GITHUB_RELEASE=	${PKGVERSION_NOREV}

MAINTAINER=	fcambus@NetBSD.org
HOMEPAGE=	https://www.ansilove.org/
COMMENT=	Library for converting ANSI, ASCII, and other formats to PNG
LICENSE=	2-clause-bsd

USE_LANGUAGES=	c99
USE_CMAKE=	yes

.include "../../graphics/gd/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
