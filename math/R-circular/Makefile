# $NetBSD: Makefile,v 1.14 2019/07/31 19:07:47 brook Exp $

CATEGORIES=	math R

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	${R_HOMEPAGE_BASE}/circular/
COMMENT=	Circular statistics
LICENSE=	gnu-gpl-v2

R_PKGNAME=	circular
R_PKGVER=	0.4-93

DEPENDS+=	R-mvtnorm>=1.0.8:../../math/R-mvtnorm

USE_LANGUAGES=	fortran c

.include "../../math/R/Makefile.extension"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
