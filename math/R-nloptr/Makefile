# $NetBSD: Makefile,v 1.1 2016/04/17 04:09:44 wen Exp $
#

CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_R_CRAN:=contrib/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	${R_HOMEPAGE_BASE}/nloptr/
COMMENT=	R interface to NLopt
LICENSE=	gnu-lgpl-v3

R_PKGNAME=	nloptr
R_PKGVER=	1.0.4

USE_LANGUAGES=	c c++

SUBST_CLASSES+=		conf
SUBST_STAGE.conf=	post-patch
SUBST_FILES.conf+=	configure
SUBST_MESSAGE.conf=	Fixing redirection of configure.
SUBST_SED.conf=		-e "s,<<<,<,g"

.include "../../math/R/Makefile.extension"
.include "../../math/nlopt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
