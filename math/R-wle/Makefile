# $NetBSD: Makefile,v 1.14 2019/07/31 20:36:36 brook Exp $

CATEGORIES=	math

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	${R_HOMEPAGE_BASE}/wle/
COMMENT=	Weighted likelihood estimation
LICENSE=	gnu-gpl-v2

R_PKGNAME=	wle
R_PKGVER=	0.9-9

DEPENDS+=	R-circular>=0.4.3:../../math/R-circular

USE_LANGUAGES+=	c fortran

.include "../../math/R/Makefile.extension"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../math/blas/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
