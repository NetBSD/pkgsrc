# $NetBSD: Makefile,v 1.6 2019/08/08 19:53:52 brook Exp $

R_PKGNAME=	nloptr
R_PKGVER=	1.2.1
CATEGORIES=	math

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	R interface to NLopt
LICENSE=	gnu-lgpl-v3

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
