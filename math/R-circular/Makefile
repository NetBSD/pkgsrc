# $NetBSD: Makefile,v 1.13 2018/08/30 12:56:34 wen Exp $

CATEGORIES=	math

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	${R_HOMEPAGE_BASE}/circular/
COMMENT=	Circular Statistics, from "Topics in circular Statistics"
LICENSE=	gnu-gpl-v2

R_PKGNAME=	circular
R_PKGVER=	0.4-93

USE_LANGUAGES=	fortran c

DEPENDS+=	R-mvtnorm>=0:../../math/R-mvtnorm

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
