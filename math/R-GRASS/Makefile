# $NetBSD: Makefile,v 1.9 2018/07/28 14:40:45 brook Exp $

CATEGORIES=	databases math

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
