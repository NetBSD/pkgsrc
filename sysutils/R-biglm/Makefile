# $NetBSD: Makefile,v 1.2 2024/12/07 03:28:28 mef Exp $

R_PKGNAME=	biglm
R_PKGVER=	0.9-3
CATEGORIES=	sysutils

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Bounded Memory Linear and Generalized Linear Models
LICENSE=	gnu-gpl-v1 OR gnu-gpl-v2 OR gnu-gpl-v3

DEPENDS+=	R-DBI>=1.1.1:../../math/R-DBI

# Package suggested but not available: 'RODBC'
# Package which this enhances but not available for checking: 'leaps'
TEST_DEPENDS+=	R-RSQLite-[0-9]*:../../databases/R-RSQLite

USE_LANGUAGES=	c fortran

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
