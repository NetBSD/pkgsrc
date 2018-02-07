# $NetBSD: Makefile,v 1.1 2018/02/07 20:40:58 minskim Exp $

CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_R_CRAN:=contrib/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	${R_HOMEPAGE_BASE}/colorspace/
COMMENT=	Color space manipulation
LICENSE=	modified-bsd

R_PKGNAME=	colorspace
R_PKGVER=	1.3-2

BUILDLINK_API_DEPENDS.R+=	R>=2.13.0
.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
