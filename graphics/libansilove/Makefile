# $NetBSD: Makefile,v 1.28 2023/11/12 13:22:06 wiz Exp $

DISTNAME=	libansilove-1.4.1
PKGREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=ansilove/}
GITHUB_RELEASE=	${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.ansilove.org/
COMMENT=	Library for converting ANSI, ASCII, and other formats to PNG
LICENSE=	2-clause-bsd

USE_LANGUAGES=	c99
USE_CMAKE=	yes

.include "../../graphics/gd/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
