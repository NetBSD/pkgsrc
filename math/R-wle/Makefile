# $NetBSD: Makefile,v 1.15 2019/08/08 19:53:55 brook Exp $

R_PKGNAME=	wle
R_PKGVER=	0.9-9
CATEGORIES=	math

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Weighted likelihood estimation
LICENSE=	gnu-gpl-v2

DEPENDS+=	R-circular>=0.4.3:../../math/R-circular

USE_LANGUAGES+=	c fortran

.include "../../math/R/Makefile.extension"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../math/blas/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
