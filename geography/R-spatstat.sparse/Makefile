# $NetBSD: Makefile,v 1.1 2021/09/20 09:56:02 mef Exp $

R_PKGNAME=	spatstat.sparse
R_PKGVER=	2.0-0
CATEGORIES=	geography

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Sparse Three-Dimensional Arrays and Linear Algebra Utilities
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

DEPENDS+=	R-spatstat.utils>=2.1.0:../../geography/R-spatstat.utils
DEPENDS+=	R-abind>=1.4.5:../../math/R-abind
DEPENDS+=	R-tensor>=1.5:../../math/R-tensor

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
