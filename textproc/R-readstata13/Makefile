# $NetBSD: Makefile,v 1.1 2019/07/31 13:53:41 brook Exp $

CATEGORIES=	textproc R

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	${R_HOMEPAGE_BASE}/readstata13/
COMMENT=	Import 'Stata' data files
LICENSE=	gnu-gpl-v2

R_PKGNAME=	readstata13
R_PKGVER=	0.9.2

USE_LANGUAGES=	c c++ fortran

.include "../../math/R/Makefile.extension"
.include "../../devel/R-Rcpp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
