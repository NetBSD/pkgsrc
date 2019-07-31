# $NetBSD: Makefile,v 1.3 2019/07/31 20:50:08 brook Exp $

CATEGORIES=	textproc R

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	${R_HOMEPAGE_BASE}/gsubfn/
COMMENT=	Utilities for strings and function arguments
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

R_PKGNAME=	gsubfn
R_PKGVER=	0.7

DEPENDS+=	R-proto>=1.0.0:../../devel/R-proto

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
