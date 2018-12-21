# $NetBSD: Makefile,v 1.4 2018/12/21 03:06:46 wen Exp $

CATEGORIES=	devel

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	${R_HOMEPAGE_BASE}/IRdisplay/
COMMENT=	Jupyter display machinery
LICENSE=	mit

DEPENDS+=	R-repr-[0-9]*:../../devel/R-repr

R_PKGNAME=	IRdisplay
R_PKGVER=	0.7.0

USE_LANGUAGES=	# none

BUILDLINK_API_DEPENDS.R+=	R>=3.0.1
.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
