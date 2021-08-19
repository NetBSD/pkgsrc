# $NetBSD: Makefile,v 1.2 2021/08/19 14:45:48 mef Exp $

R_PKGNAME=	tinytest
R_PKGVER=	1.3.1
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Lightweight and Feature Complete Unit Testing Framework
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	# none

TEST_DEPENDS+=	tex-xcolor-[0-9]*:../../print/tex-xcolor
TEST_DEPENDS+=	tex-sectsty-[0-9]*:../../print/tex-sectsty

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
