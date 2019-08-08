# $NetBSD: Makefile,v 1.8 2019/08/08 19:53:40 brook Exp $

R_PKGNAME=	repr
R_PKGVER=	1.0.1
CATEGORIES=	devel

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Serializable representations
LICENSE=	gnu-gpl-v3

DEPENDS+=	R-base64enc>=0.1.3:../../converters/R-base64enc
DEPENDS+=	R-pillar>=1.4.0:../../misc/R-pillar
DEPENDS+=	R-htmltools>=0.3.6:../../textproc/R-htmltools
DEPENDS+=	R-jsonlite>=1.6:../../textproc/R-jsonlite

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
