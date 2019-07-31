# $NetBSD: Makefile,v 1.16 2019/07/31 20:56:33 brook Exp $

CATEGORIES=	textproc R

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	${R_HOMEPAGE_BASE}/stringi/
COMMENT=	Character string processing facilities
LICENSE=	modified-bsd	# + file LICENSE

R_PKGNAME=	stringi
R_PKGVER=	1.4.3

USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

.include "../../math/R/Makefile.extension"
.include "../../textproc/icu/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
