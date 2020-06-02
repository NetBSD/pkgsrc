# $NetBSD: Makefile,v 1.3 2020/06/02 08:24:49 adam Exp $

R_PKGNAME=	xml2
R_PKGVER=	1.2.2
PKGREVISION=	2
CATEGORIES=	textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Parse XML
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

USE_TOOLS+=	perl
USE_LANGUAGES=	c c++

.include "../../math/R/Makefile.extension"
.include "../../devel/R-Rcpp/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
