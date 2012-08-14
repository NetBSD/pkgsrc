# $NetBSD: Makefile,v 1.9 2012/08/14 17:07:57 asau Exp $
#

CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_R_CRAN:=contrib/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	${R_HOMEPAGE_BASE}/wle/
COMMENT=	Weighted Likelihood Estimation
LICENSE=	gnu-gpl-v2

R_PKGNAME=	wle
R_PKGVER=	0.9-4

PKG_DESTDIR_SUPPORT=	none

USE_LANGUAGES+=	c fortran

DEPENDS+=	R-circular>=0.4.3:../../math/R-circular

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../math/R/Makefile.extension"
.include "../../math/blas/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
