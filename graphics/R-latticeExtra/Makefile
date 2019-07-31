# $NetBSD: Makefile,v 1.4 2019/07/31 16:09:08 brook Exp $

CATEGORIES=	graphics R

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	${R_HOMEPAGE_BASE}/latticeExtra/
COMMENT=	Extra graphical utilities based on lattice
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

R_PKGNAME=	latticeExtra
R_PKGVER=	0.6-28

DEPENDS+=	R-RColorBrewer>=1.0.5:../../math/R-RColorBrewer

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
