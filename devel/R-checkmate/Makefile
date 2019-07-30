# $NetBSD: Makefile,v 1.1 2019/07/30 22:31:32 brook Exp $

CATEGORIES=	devel R

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	${R_HOMEPAGE_BASE}/checkmate/
COMMENT=	Fast and versatile argument checks
LICENSE=	modified-bsd

R_PKGNAME=	checkmate
R_PKGVER=	1.9.4

DEPENDS+=	R-backports>=1.1.0:../../math/R-backports

USE_LANGUAGES=	c

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
