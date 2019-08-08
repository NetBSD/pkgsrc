# $NetBSD: Makefile,v 1.15 2019/08/08 19:53:47 brook Exp $

R_PKGNAME=	circular
R_PKGVER=	0.4-93
CATEGORIES=	math

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Circular statistics
LICENSE=	gnu-gpl-v2

DEPENDS+=	R-mvtnorm>=1.0.8:../../math/R-mvtnorm

USE_LANGUAGES=	fortran c

.include "../../math/R/Makefile.extension"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
