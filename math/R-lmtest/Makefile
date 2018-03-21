# $NetBSD: Makefile,v 1.1 2018/03/21 15:26:08 minskim Exp $

CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_R_CRAN:=contrib/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	${R_HOMEPAGE_BASE}/lmtest/
COMMENT=	Testing linear regression models
LICENSE=	gnu-gpl-v2

R_PKGNAME=	lmtest
R_PKGVER=	0.9-35

DEPENDS+=	R-zoo-[0-9]*:../../math/R-zoo

USE_LANGUAGES=	c fortran

BUILDLINK_ABI_DEPENDS.R+=	R>=2.10.0
.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
