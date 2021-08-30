# $NetBSD: Makefile,v 1.4 2021/08/30 01:02:36 mef Exp $

R_PKGNAME=	sys
R_PKGVER=	3.4
CATEGORIES=	sysutils

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Powerful and reliable tools for running system commands in R
LICENSE=	mit

TEST_DEPENDS+=	R-unix-[0-9]*:../../sysutils/R-unix

USE_LANGUAGES=	c

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
