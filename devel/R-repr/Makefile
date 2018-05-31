# $NetBSD: Makefile,v 1.2 2018/05/31 01:40:25 wen Exp $

CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_R_CRAN:=contrib/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	${R_HOMEPAGE_BASE}/repr/
COMMENT=	Serializable representations
LICENSE=	gnu-gpl-v3

DEPENDS+=	R-htmltools-[0-9]*:../../textproc/R-htmltools
DEPENDS+=	R-base64enc-[0-9]*:../../converters/R-base64enc

R_PKGNAME=	repr
R_PKGVER=	0.15.0

USE_LANGUAGES=	# none

BUILDLINK_API_DEPENDS.R+=	R>=3.0.1
.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
