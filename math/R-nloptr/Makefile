# $NetBSD: Makefile,v 1.7 2020/05/03 07:44:53 rillig Exp $

R_PKGNAME=	nloptr
R_PKGVER=	1.2.1
CATEGORIES=	math

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	R interface to NLopt
LICENSE=	gnu-lgpl-v3

USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config

.include "../../math/R/Makefile.extension"
.include "../../math/nlopt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
