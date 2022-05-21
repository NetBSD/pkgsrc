# $NetBSD: Makefile,v 1.6 2022/05/21 13:14:49 mef Exp $

R_PKGNAME=	VGAM
R_PKGVER=	1.1-6

MAINTAINER=	mishka@NetBSD.org
COMMENT=	Vector generalized linear and additive models
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	c fortran

# Package suggested but not available: 'VGAMextra'
# Package which this enhances but not available for checking: 'VGAMdata'


.include "../../math/R/Makefile.extension"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
