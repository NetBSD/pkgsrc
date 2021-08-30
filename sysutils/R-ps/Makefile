# $NetBSD: Makefile,v 1.3 2021/08/30 00:53:15 mef Exp $

R_PKGNAME=	ps
R_PKGVER=	1.6.0
CATEGORIES=	sysutils

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	List, query, manipulate system processes
LICENSE=	modified-bsd

TEST_DEPENDS+=	R-pingr-[0-9]*:../../net/R-pingr

USE_LANGUAGES=	c

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
