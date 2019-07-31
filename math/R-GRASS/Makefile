# $NetBSD: Makefile,v 1.10 2019/07/31 18:12:42 brook Exp $

CATEGORIES=	math databases geography R

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	${R_HOMEPAGE_BASE}/GRASS/
COMMENT=	Interface between GRASS 5.0 geographical information system and R

R_PKGNAME=	GRASS
R_PKGVER=	0.3-8

USE_LANGUAGES=	c

post-extract:
	${ECHO} 'exportPattern(".")' > ${WRKSRC}/NAMESPACE

.include "../../math/R/Makefile.extension"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
