# $NetBSD: Makefile,v 1.12 2014/03/09 14:22:53 wen Exp $

CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_R_CRAN:=contrib/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	${R_HOMEPAGE_BASE}/wle/
COMMENT=	Weighted Likelihood Estimation
LICENSE=	gnu-gpl-v2

DEPENDS+=	R-circular>=0.4.3:../../math/R-circular

R_PKGNAME=	wle
R_PKGVER=	0.9-9

USE_LANGUAGES+=	c fortran

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../math/R/Makefile.extension"
.include "../../math/blas/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
