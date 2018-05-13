# $NetBSD: Makefile,v 1.36 2018/05/13 12:14:17 markd Exp $

DISTNAME=	texlive-20180414-source
PKGNAME=	ttf2pk-2.0
PKGREVISION=	4
CATEGORIES=	fonts print
MASTER_SITES=	ftp://tug.org/historic/systems/texlive/2018/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	bernhard@SDG.de
HOMEPAGE=	https://www.freetype.org/
COMMENT=	TrueType to TeX PK font converter

EXTRACT_ELEMENTS=	${DISTNAME}/build-aux \
			${DISTNAME}/texk/ttf2pk2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
WRKSRC=		${WRKDIR}/${DISTNAME}/texk/ttf2pk2

CONFIG_GUESS_OVERRIDE+=	${WRKDIR}/${DISTNAME}/build-aux/config.guess
CONFIG_SUB_OVERRIDE+=	${WRKDIR}/${DISTNAME}/build-aux/config.sub

CONFIGURE_ARGS+=	--with-system-kpathsea
CONFIGURE_ARGS+=	--with-system-zlib \
		--with-zlib-includes=${BUILDLINK_PREFIX.zlib}/include \
		--with-zlib-libdir=${BUILDLINK_PREFIX.zlib}/lib
CONFIGURE_ARGS+=	--with-system-freetype2
CONFIGURE_ENV+=		FT2_CONFIG=pkg-config \
			PKG_CONFIG=${TOOLS_CMD.pkg-config}

.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
BUILDLINK_API_DEPENDS.kpathsea+= kpathsea>=6.2.1
.include "../../print/kpathsea/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
