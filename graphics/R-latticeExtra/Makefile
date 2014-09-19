# $NetBSD: Makefile,v 1.1 2014/09/19 16:50:27 brook Exp $

CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_R_CRAN:=contrib/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	${R_HOMEPAGE_BASE}/latticeExtra/
COMMENT=	Extra graphical utilities based on lattice
LICENSE=	gnu-gpl-v2

R_PKGNAME=	latticeExtra
R_PKGVER=	0.6-26

DEPENDS+=	R-RColorBrewer>=1.0.5:../../math/R-RColorBrewer

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
