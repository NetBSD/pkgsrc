# $NetBSD: Makefile,v 1.10 2020/05/01 09:31:44 fcambus Exp $

DISTNAME=	libansilove-1.2.2
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
