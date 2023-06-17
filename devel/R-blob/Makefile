# $NetBSD: Makefile,v 1.5 2023/06/17 13:04:42 mef Exp $

R_PKGNAME=	blob
R_PKGVER=	1.2.4
CATEGORIES=	devel

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Simple S3 class for representing vectors of binary data ('BLOBS')
LICENSE=	gnu-gpl-v3

DEPENDS+=	R-rlang>=0.4.0:../../devel/R-rlang
DEPENDS+=	R-prettyunits>=1.0.2:../../math/R-prettyunits
DEPENDS+=	R-vctrs>=0.2.0:../../math/R-vctrs

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
