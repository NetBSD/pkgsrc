# $NetBSD: Makefile,v 1.5 2019/07/31 14:54:15 brook Exp $

CATEGORIES=	devel R

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	${R_HOMEPAGE_BASE}/IRdisplay/
COMMENT=	Jupyter display machinery
LICENSE=	mit

DEPENDS+=	R-repr>=0.19.2:../../devel/R-repr

R_PKGNAME=	IRdisplay
R_PKGVER=	0.7.0

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
