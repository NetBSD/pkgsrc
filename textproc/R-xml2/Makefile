# $NetBSD: Makefile,v 1.7 2021/05/24 19:54:22 wiz Exp $

R_PKGNAME=	xml2
R_PKGVER=	1.2.2
PKGREVISION=	6
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
