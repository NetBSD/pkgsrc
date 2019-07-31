# $NetBSD: Makefile,v 1.3 2019/07/31 14:36:45 brook Exp $

CATEGORIES=	databases R

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/r-dbi/RSQLite
COMMENT=	'SQLite' interface for R
LICENSE=	gnu-lgpl-v2 OR gnu-lgpl-v2.1 OR gnu-lgpl-v3

R_PKGNAME=	RSQLite
R_PKGVER=	2.1.2

DEPENDS+=	R-bit64>=0.9.7:../../devel/R-bit64
DEPENDS+=	R-blob>=1.2.0:../../devel/R-blob
DEPENDS+=	R-memoise>=1.1.0:../../devel/R-memoise
DEPENDS+=	R-pkgconfig>=2.0.2:../../devel/R-pkgconfig
DEPENDS+=	R-DBI>=1.0.0:../../math/R-DBI

USE_LANGUAGES+=	c c++

.include "../../math/R/Makefile.extension"
.include "../../devel/R-BH/buildlink3.mk"
.include "../../devel/R-Rcpp/buildlink3.mk"
.include "../../devel/R-plogr/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
