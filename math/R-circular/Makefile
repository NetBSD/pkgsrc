# $NetBSD: Makefile,v 1.11 2014/03/09 14:15:43 wen Exp $

CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_R_CRAN:=contrib/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	${R_HOMEPAGE_BASE}/circular/
COMMENT=	Circular Statistics, from "Topics in circular Statistics"
LICENSE=	gnu-gpl-v2

R_PKGNAME=	circular
R_PKGVER=	0.4-7

USE_LANGUAGES=	fortran c

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
