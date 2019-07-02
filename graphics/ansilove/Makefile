# $NetBSD: Makefile,v 1.8 2019/07/02 15:46:04 fcambus Exp $

DISTNAME=	ansilove-4.0.1
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
