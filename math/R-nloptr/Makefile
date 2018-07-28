# $NetBSD: Makefile,v 1.4 2018/07/28 14:40:49 brook Exp $
#

CATEGORIES=	math

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	${R_HOMEPAGE_BASE}/nloptr/
COMMENT=	R interface to NLopt
LICENSE=	gnu-lgpl-v3

R_PKGNAME=	nloptr
R_PKGVER=	1.0.4

USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config

SUBST_CLASSES+=		conf
SUBST_STAGE.conf=	pre-configure
SUBST_FILES.conf+=	configure
SUBST_MESSAGE.conf=	Fixing redirection of configure.
SUBST_SED.conf=		-e "s,<<<,<,g"

.include "../../math/R/Makefile.extension"
.include "../../math/nlopt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
