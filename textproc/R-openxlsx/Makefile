# $NetBSD: Makefile,v 1.1 2019/07/31 13:48:46 brook Exp $

CATEGORIES=	textproc R

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	${R_HOMEPAGE_BASE}/openxlsx/
COMMENT=	Read, write and edit XLSX files
LICENSE=	mit

R_PKGNAME=	openxlsx
R_PKGVER=	4.1.0.1

DEPENDS+=	R-zip>=2.0.3:../../archivers/R-zip

USE_LANGUAGES=	c c++

.include "../../math/R/Makefile.extension"
.include "../../devel/R-Rcpp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
