# $NetBSD: Makefile,v 1.7 2019/07/31 15:21:50 brook Exp $

CATEGORIES=	devel R

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	${R_HOMEPAGE_BASE}/evaluate/
COMMENT=	Parsing and evaluation tools
LICENSE=	mit

R_PKGNAME=	evaluate
R_PKGVER=	0.14

DEPENDS+=	R-stringr>=0.6.2:../../textproc/R-stringr

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
