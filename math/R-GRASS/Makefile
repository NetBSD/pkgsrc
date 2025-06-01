# $NetBSD: Makefile,v 1.12 2025/06/01 21:48:47 thor Exp $

R_PKGNAME=	GRASS
R_PKGVER=	0.3-8
CATEGORIES=	math databases geography

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Interface between GRASS 5.0 geographical information system and R

USE_LANGUAGES=	c

CONFIGURE_ARGS+=	--with-xdr-include=${BUILDLINK_PREFIX.libtirpc}/include/tirpc

post-extract:
	${ECHO} 'exportPattern(".")' > ${WRKSRC}/NAMESPACE

.include "../../math/R/Makefile.extension"
.include "../../devel/zlib/buildlink3.mk"
.include "../../devel/libtirpc/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
