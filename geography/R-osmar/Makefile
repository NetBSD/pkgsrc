# $NetBSD: Makefile,v 1.1 2020/08/09 15:16:52 brook Exp $

R_PKGNAME=	osmar
R_PKGVER=	1.1-7
CATEGORIES=	geography

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	OpenStreetMap and R
LICENSE=	gnu-gpl-v2

DEPENDS+=	R-geosphere>=1.5.7:../../geography/R-geosphere
DEPENDS+=	R-RCurl>=1.98.1.1:../../www/R-RCurl

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../math/R-XML/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
