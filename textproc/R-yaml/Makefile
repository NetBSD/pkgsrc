# $NetBSD: Makefile,v 1.7 2023/06/03 14:16:09 mef Exp $

R_PKGNAME=	yaml
R_PKGVER=	2.3.7
CATEGORIES=	textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Methods to convert R data to YAML and back
LICENSE=	modified-bsd

TEST_DEPENDS+=	R-RUnit-[0-9]*:../../devel/R-RUnit

USE_LANGUAGES=	c

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
