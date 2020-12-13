# $NetBSD: Makefile,v 1.3 2020/12/13 23:36:57 mef Exp $

R_PKGNAME=	clipr
R_PKGVER=	0.7.1
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Read and write from the system clipboard
LICENSE=	gnu-gpl-v3

TEST_DEPENDS+=	R-rmarkdown-[0-9]*:../../textproc/R-rmarkdown

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
