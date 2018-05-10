# $NetBSD: Makefile,v 1.2 2018/05/10 00:09:29 minskim Exp $

DISTNAME=	RSQLite_2.1.1
CATEGORIES=	databases

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/r-dbi/RSQLite
COMMENT=	'SQLite' Interface for R
LICENSE=	gnu-lgpl-v2

DEPENDS+=	R-bit64-[0-9]*:../../devel/R-bit64
DEPENDS+=	R-blob>=1.1.1:../../devel/R-blob
DEPENDS+=	R-DBI>=1.0.0:../../math/R-DBI
DEPENDS+=	R-memoise-[0-9]*:../../devel/R-memoise
DEPENDS+=	R-pkgconfig-[0-9]*:../../devel/R-pkgconfig

USE_LANGUAGES+=	c c++

BUILDLINK_API_DEPENDS.R+=	R>=3.1.0
.include "../../math/R/Makefile.extension"
.include "../../devel/R-BH/buildlink3.mk"
BUILDLINK_API_DEPENDS.R-Rcpp+=	R-Rcpp>=0.12.7
.include "../../devel/R-Rcpp/buildlink3.mk"
.include "../../devel/R-plogr/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
