# $NetBSD: Makefile,v 1.30 2023/11/08 13:21:04 wiz Exp $

R_PKGNAME=	stringi
R_PKGVER=	1.7.12
PKGREVISION=	1
CATEGORIES=	textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Character string processing facilities
LICENSE=	modified-bsd	# + file LICENSE

USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

.include "../../math/R/Makefile.extension"
.include "../../textproc/icu/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
