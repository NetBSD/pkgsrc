# $NetBSD: Makefile,v 1.6 2026/06/09 23:13:07 mef Exp $

R_PKGNAME=	reshape2
R_PKGVER=	1.4.5
#CATEGORIES=	math

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Flexibly reshape data: a reboot of the reshape package
LICENSE=	mit

DEPENDS+=	R-plyr>=1.8.1:../../math/R-plyr
DEPENDS+=	R-stringr>=1.4.0:../../textproc/R-stringr

USE_LANGUAGES=	c++

.include "../../mk/bsd.prefs.mk"
pre-patch:
.if ${OPSYS} != SunOS
	${CP} ${FILESDIR}/Makevars ${WRKSRC}/src/
.endif

.include "../../math/R/Makefile.extension"
.include "../../devel/R-Rcpp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
