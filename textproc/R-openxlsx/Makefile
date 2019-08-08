# $NetBSD: Makefile,v 1.2 2019/08/08 19:53:57 brook Exp $

R_PKGNAME=	openxlsx
R_PKGVER=	4.1.0.1
CATEGORIES=	textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Read, write and edit XLSX files
LICENSE=	mit

DEPENDS+=	R-zip>=2.0.3:../../archivers/R-zip

USE_LANGUAGES=	c c++

.include "../../math/R/Makefile.extension"
.include "../../devel/R-Rcpp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
