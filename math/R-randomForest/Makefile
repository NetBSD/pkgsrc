# $NetBSD: Makefile,v 1.12 2023/06/10 11:58:44 mef Exp $

R_PKGNAME=	randomForest
R_PKGVER=	4.7-1.1

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Breiman and Cutler's Random Forests for Classification and Regression
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

USE_LANGUAGES=	c fortran

TEST_DEPENDS+=	R-RColorBrewer-[0-9]*:../../math/R-RColorBrewer

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
