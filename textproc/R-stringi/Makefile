# $NetBSD: Makefile,v 1.7 2017/04/27 17:06:56 joerg Exp $

PKGREVISION=	1
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
