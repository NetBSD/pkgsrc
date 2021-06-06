# $NetBSD: Makefile,v 1.5 2021/06/06 06:38:29 mef Exp $

R_PKGNAME=	reshape2
R_PKGVER=	1.4.4
#CATEGORIES=	math

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Flexibly reshape data: a reboot of the reshape package
LICENSE=	mit

DEPENDS+=	R-plyr>=1.8.1:../../math/R-plyr
DEPENDS+=	R-stringr>=1.4.0:../../textproc/R-stringr

USE_LANGUAGES=	c++

.include "../../math/R/Makefile.extension"
.include "../../devel/R-Rcpp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
