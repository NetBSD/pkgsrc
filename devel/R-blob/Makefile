# $NetBSD: Makefile,v 1.2 2019/07/31 15:16:44 brook Exp $

CATEGORIES=	devel R

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/tidyverse/blob
COMMENT=	Simple S3 class for representing vectors of binary data ('BLOBS')
LICENSE=	gnu-gpl-v3

R_PKGNAME=	blob
R_PKGVER=	1.2.0

DEPENDS+=	R-rlang>=0.4.0:../../devel/R-rlang
DEPENDS+=	R-prettyunits>=1.0.2:../../math/R-prettyunits
DEPENDS+=	R-vctrs>=0.2.0:../../math/R-vctrs

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
