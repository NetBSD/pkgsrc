# $NetBSD: Makefile,v 1.3 2021/09/11 01:29:30 mef Exp $

R_PKGNAME=	readstata13
R_PKGVER=	0.10.0
CATEGORIES=	textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Import 'Stata' data files
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	c c++ fortran

.include "../../math/R/Makefile.extension"
.include "../../devel/R-Rcpp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
