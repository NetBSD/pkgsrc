# $NetBSD: Makefile,v 1.3 2020/09/20 14:46:00 mef Exp $

R_PKGNAME=	withr
R_PKGVER=	2.2.0
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Run code 'with' temporarily modified global state
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

TEST_DEPENDS+=	R-RSQLite-[0-9]*:../../databases/R-RSQLite

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
