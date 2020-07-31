# $NetBSD: Makefile,v 1.1 2020/07/31 20:11:23 brook Exp $

R_PKGNAME=	lifecycle
R_PKGVER=	0.2.0
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Manage the Life Cycle of your Package Functions
LICENSE=	gnu-gpl-v3

DEPENDS+=	R-glue>=1.3.1:../../devel/R-glue
DEPENDS+=	R-rlang>=0.4.0:../../devel/R-rlang

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
