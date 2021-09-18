# $NetBSD: Makefile,v 1.3 2021/09/18 01:59:15 mef Exp $

R_PKGNAME=	mnormt
R_PKGVER=	2.0.2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	${R_HOMEPAGE_BASE}/mnormt/
COMMENT=	Multivariate normal and t distributions
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

DEPENDS+=	R-tmvnsim-[0-9]*:../../math/R-tmvnsim

USE_LANGUAGES+=	c fortran

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
