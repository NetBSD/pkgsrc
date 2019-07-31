# $NetBSD: Makefile,v 1.1 2019/07/31 13:13:39 brook Exp $

CATEGORIES=	math R

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	${R_HOMEPAGE_BASE}/ellipsis/
COMMENT=	Tools for working with ...
LICENSE=	gnu-gpl-v3

R_PKGNAME=	ellipsis
R_PKGVER=	0.2.0.1

DEPENDS+=	R-rlang>=0.3.0:../../devel/R-rlang

USE_LANGUAGES=	c

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
