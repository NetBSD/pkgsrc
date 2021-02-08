# $NetBSD: Makefile,v 1.5 2021/02/08 12:05:40 mef Exp $

R_PKGNAME=	withr
R_PKGVER=	2.4.1
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Run code 'with' temporarily modified global state
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

TEST_DEPENDS+=	R-RSQLite-[0-9]*:../../databases/R-RSQLite

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
