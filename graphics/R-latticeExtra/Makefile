# $NetBSD: Makefile,v 1.2 2016/04/09 11:02:10 wen Exp $

CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_R_CRAN:=contrib/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	${R_HOMEPAGE_BASE}/latticeExtra/
COMMENT=	Extra graphical utilities based on lattice
LICENSE=	gnu-gpl-v2

R_PKGNAME=	latticeExtra
R_PKGVER=	0.6-28

DEPENDS+=	R-RColorBrewer>=1.0.5:../../math/R-RColorBrewer

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
