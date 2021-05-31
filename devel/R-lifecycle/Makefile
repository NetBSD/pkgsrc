# $NetBSD: Makefile,v 1.2 2021/05/31 22:15:16 mef Exp $

R_PKGNAME=	lifecycle
R_PKGVER=	1.0.0
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Manage the Life Cycle of your Package Functions
LICENSE=	gnu-gpl-v3

DEPENDS+=	R-glue>=1.3.1:../../devel/R-glue
DEPENDS+=	R-rlang>=0.4.0:../../devel/R-rlang

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
