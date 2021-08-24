# $NetBSD: Makefile,v 1.6 2021/08/24 11:46:35 mef Exp $

R_PKGNAME=	yaml
R_PKGVER=	2.2.1
CATEGORIES=	textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Methods to convert R data to YAML and back
LICENSE=	modified-bsd

TEST_DEPENDS+=	R-RUnit-[0-9]*:../../devel/R-RUnit

USE_LANGUAGES=	c

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
