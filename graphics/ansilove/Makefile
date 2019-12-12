# $NetBSD: Makefile,v 1.13 2019/12/12 10:04:53 fcambus Exp $

DISTNAME=	ansilove-4.0.6
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=ansilove/}

MAINTAINER=	fcambus@NetBSD.org
HOMEPAGE=	https://www.ansilove.org/
COMMENT=	ANSI and ASCII art to PNG converter
LICENSE=	2-clause-bsd

USE_LANGUAGES=	c99
USE_CMAKE=	yes

.include "../../graphics/libansilove/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
