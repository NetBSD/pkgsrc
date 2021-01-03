# $NetBSD: Makefile,v 1.6 2021/01/03 10:49:31 mef Exp $

R_PKGNAME=	SparseM
R_PKGVER=	1.78

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Sparse linear algebra
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

TEST_DEPENDS+=	tex-ec-[0-9]*:../../fonts/tex-ec

USE_LANGUAGES=	c fortran

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
