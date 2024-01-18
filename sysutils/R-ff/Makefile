# $NetBSD: Makefile,v 1.2 2024/01/18 23:31:12 mef Exp $

R_PKGNAME=	ff
R_PKGVER=	4.0.12
CATEGORIES=	sysutils

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Fast Access Functions for Large Data on Disk
LICENSE=	gnu-gpl-v3 OR gnu-gpl-v2	# See also LICENSE file

DEPENDS+=	R-bit>=4.0.0:../../devel/R-bit

TEST_DEPENDS+=	R-biglm-[0-9]*:../../sysutils/R-biglm
TEST_DEPENDS+=	R-testthat-[0-9]*:../../devel/R-testthat

USE_LANGUAGES=	c c++

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
