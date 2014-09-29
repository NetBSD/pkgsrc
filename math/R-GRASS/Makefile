# $NetBSD: Makefile,v 1.8 2014/09/29 15:11:43 jperkin Exp $

CATEGORIES=	databases math
MASTER_SITES=	${MASTER_SITE_R_CRAN:=contrib/}

MAINTAINER=	mchittur@cs.nmsu.edu
HOMEPAGE=	${R_HOMEPAGE_BASE}/GRASS/
COMMENT=	Interface between GRASS 5.0 geographical information system and R

R_PKGNAME=	GRASS
R_PKGVER=	0.3-8

post-extract:
	echo 'exportPattern("^[^\\.]")' > ${WRKSRC}/NAMESPACE

.include "../../devel/zlib/buildlink3.mk"
.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
