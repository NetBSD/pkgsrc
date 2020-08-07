# $NetBSD: Makefile,v 1.1 2020/08/07 00:25:49 brook Exp $

CATEGORIES=	geography
MASTER_SITES=	${MASTER_SITE_R_CRAN:=contrib/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	${R_HOMEPAGE_BASE}/geosphere/
COMMENT=	Spherical Trigonometry
LICENSE=	gnu-gpl-v3

R_PKGNAME=	geosphere
R_PKGVER=	1.5-10

DEPENDS+=	R-sp>=1.2.5:../../math/R-sp

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
