# $NetBSD: Makefile,v 1.13 2018/07/28 14:40:52 brook Exp $

PKGREVISION=	2
CATEGORIES=	textproc

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
