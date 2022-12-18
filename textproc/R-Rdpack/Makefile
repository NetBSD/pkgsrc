# $NetBSD: Makefile,v 1.1 2022/12/18 06:13:31 mef Exp $

R_PKGNAME=	Rdpack
R_PKGVER=	2.4
CATEGORIES=	textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Update and Manipulate Rd Documentation Objects
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

DEPENDS+=	R-rbibutils-[0-9]*:../../textproc/R-rbibutils

# Package suggested but not available: 'gbRd'


USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
