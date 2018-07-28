# $NetBSD: Makefile,v 1.2 2018/07/28 14:40:44 brook Exp $

CATEGORIES=	graphics

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	${R_HOMEPAGE_BASE}/colorspace/
COMMENT=	Color space manipulation
LICENSE=	modified-bsd

R_PKGNAME=	colorspace
R_PKGVER=	1.3-2

BUILDLINK_API_DEPENDS.R+=	R>=2.13.0
.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
