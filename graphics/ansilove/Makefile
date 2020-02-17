# $NetBSD: Makefile,v 1.15 2020/02/17 14:44:54 fcambus Exp $

DISTNAME=	ansilove-4.1.0
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
