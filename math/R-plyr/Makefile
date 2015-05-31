# $NetBSD: Makefile,v 1.4 2015/05/31 03:54:07 wen Exp $

CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_R_CRAN:=contrib/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	${R_HOMEPAGE_BASE}/plyr/
COMMENT=	Tools for splitting, applying and combining data
LICENSE=	mit

R_PKGNAME=	plyr
R_PKGVER=	1.8.2

USE_LANGUAGES+=	c++

.include "../../math/R/Makefile.extension"
.include "../../devel/R-Rcpp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
