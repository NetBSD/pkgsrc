# $NetBSD: Makefile,v 1.2 2020/12/14 03:14:38 mef Exp $

R_PKGNAME=	rprojroot
R_PKGVER=	2.0.2
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Finding files in project subdirectories
LICENSE=	gnu-gpl-v3

DEPENDS+=	R-backports>=1.1.4:../../math/R-backports

TEST_DEPENDS+=	R-lifecycle-[0-9]*:../../devel/R-lifecycle

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
