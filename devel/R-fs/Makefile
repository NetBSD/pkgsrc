# $NetBSD: Makefile,v 1.1 2019/08/09 18:28:06 brook Exp $

R_PKGNAME=	fs
R_PKGVER=	1.3.1
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Cross-platform file system operations based on 'libuv'
LICENSE=	gnu-gpl-v3

USE_TOOLS+=	gmake
USE_LANGUAGES=	c c++

.include "../../math/R/Makefile.extension"
.include "../../devel/R-Rcpp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
