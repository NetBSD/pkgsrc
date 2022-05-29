# $NetBSD: Makefile,v 1.4 2022/05/29 00:27:37 wen Exp $

R_PKGNAME=	blob
R_PKGVER=	1.2.3
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
