# $NetBSD: Makefile,v 1.8 2017/09/18 09:53:35 maya Exp $

PKGREVISION=	2
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_R_CRAN:=contrib/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	${R_HOMEPAGE_BASE}/stringi/
COMMENT=	Character String Processing Facilities
LICENSE=	modified-bsd

R_PKGNAME=	stringi
R_PKGVER=	1.1.2

USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config

.include "../../textproc/icu/buildlink3.mk"
.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
