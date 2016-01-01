# $NetBSD: Makefile,v 1.1 2016/01/01 12:59:19 wen Exp $

CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_R_CRAN:=contrib/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	${R_HOMEPAGE_BASE}/stringi/
COMMENT=	Character String Processing Facilities
LICENSE=	modified-bsd

R_PKGNAME=	stringi
R_PKGVER=	1.0-1

USE_LANGUAGES=	c c++

.include "../../textproc/icu/buildlink3.mk"
.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
