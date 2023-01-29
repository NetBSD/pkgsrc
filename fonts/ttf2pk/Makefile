# $NetBSD: Makefile,v 1.41 2023/01/29 21:16:05 ryoon Exp $

.include "../../print/texlive/Makefile.common"

PKGNAME=	ttf2pk-2.0
PKGREVISION=	9
CATEGORIES=	fonts print

MAINTAINER=	bernhard@SDG.de
HOMEPAGE=	https://www.freetype.org/
COMMENT=	TrueType to TeX PK font converter

EXTRACT_ELEMENTS+=	${DISTNAME}/texk/ttf2pk2

WRKSRC=		${WRKDIR}/${DISTNAME}/texk/ttf2pk2

CONFIGURE_ARGS+=	--with-system-kpathsea
CONFIGURE_ARGS+=	--with-system-zlib
CONFIGURE_ARGS+=	--with-zlib-includes=${BUILDLINK_PREFIX.zlib}/include
CONFIGURE_ARGS+=	--with-zlib-libdir=${BUILDLINK_PREFIX.zlib}/lib
CONFIGURE_ARGS+=	--with-system-freetype2

.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
BUILDLINK_API_DEPENDS.kpathsea+= kpathsea>=6.2.1
.include "../../print/kpathsea/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
