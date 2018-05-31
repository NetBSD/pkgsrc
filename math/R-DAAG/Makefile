# $NetBSD: Makefile,v 1.12 2018/05/31 00:56:33 wen Exp $

CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_R_CRAN:=contrib/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	${R_HOMEPAGE_BASE}/DAAG/
COMMENT=	Data Analysis And Graphics data and functions
LICENSE=	gnu-gpl-v3

R_PKGNAME=	DAAG
R_PKGVER=	1.22

DEPENDS+=	R-latticeExtra>=0.6.26:../../graphics/R-latticeExtra

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
