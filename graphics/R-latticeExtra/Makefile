# $NetBSD: Makefile,v 1.3 2018/07/28 14:40:44 brook Exp $

CATEGORIES=	graphics

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	${R_HOMEPAGE_BASE}/latticeExtra/
COMMENT=	Extra graphical utilities based on lattice
LICENSE=	gnu-gpl-v2

R_PKGNAME=	latticeExtra
R_PKGVER=	0.6-28

DEPENDS+=	R-RColorBrewer>=1.0.5:../../math/R-RColorBrewer

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
