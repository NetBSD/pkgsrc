# $NetBSD: Makefile,v 1.26 2022/04/23 14:43:57 mef Exp $

R_PKGNAME=	stringi
R_PKGVER=	1.7.6
CATEGORIES=	textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Character string processing facilities
LICENSE=	modified-bsd	# + file LICENSE

USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

.include "../../math/R/Makefile.extension"
.include "../../textproc/icu/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
