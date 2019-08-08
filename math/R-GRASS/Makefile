# $NetBSD: Makefile,v 1.11 2019/08/08 19:53:44 brook Exp $

R_PKGNAME=	GRASS
R_PKGVER=	0.3-8
CATEGORIES=	math databases geography

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Interface between GRASS 5.0 geographical information system and R

USE_LANGUAGES=	c

post-extract:
	${ECHO} 'exportPattern(".")' > ${WRKSRC}/NAMESPACE

.include "../../math/R/Makefile.extension"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
