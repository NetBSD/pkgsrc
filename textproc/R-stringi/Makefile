# $NetBSD: Makefile,v 1.11 2018/04/14 07:34:42 adam Exp $

PKGREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_R_CRAN:=contrib/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	${R_HOMEPAGE_BASE}/stringi/
COMMENT=	Character String Processing Facilities
LICENSE=	modified-bsd

R_PKGNAME=	stringi
R_PKGVER=	1.1.6

USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config

.include "../../textproc/icu/buildlink3.mk"
BUILDLINK_API_DEPENDS.R+=	R>=2.14
.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
