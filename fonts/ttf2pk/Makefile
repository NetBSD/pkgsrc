# $NetBSD: Makefile,v 1.46 2026/04/03 03:25:16 markd Exp $

.include "../../print/texlive/Makefile.common"

PKGNAME=	ttf2pk-2.0
PKGREVISION=	14
CATEGORIES=	fonts print

MAINTAINER=	bernhard@SDG.de
HOMEPAGE=	https://www.freetype.org/
COMMENT=	TrueType to TeX PK font converter
LICENSE=	gnu-gpl-v2

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
