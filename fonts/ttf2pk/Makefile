# $NetBSD: Makefile,v 1.29 2015/02/23 18:28:51 joerg Exp $

DISTNAME=	texlive-20130530-source
PKGNAME=	ttf2pk-1.5
PKGREVISION=	6
CATEGORIES=	fonts print
MASTER_SITES=	${MASTER_SITE_TEX_CTAN:=systems/texlive/Source/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	bernhard@SDG.de
HOMEPAGE=	http://www.freetype.org/
COMMENT=	TrueType to TeX PK font converter

EXTRACT_ELEMENTS=	${DISTNAME}/build-aux \
			${DISTNAME}/texk/ttf2pk

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}/texk/ttf2pk

CONFIG_GUESS_OVERRIDE+=	${WRKDIR}/${DISTNAME}/build-aux/config.guess
CONFIG_SUB_OVERRIDE+=	${WRKDIR}/${DISTNAME}/build-aux/config.sub

CONFIGURE_ARGS+=	--with-system-kpathsea \
		--with-kpathsea-includes=${BUILDLINK_PREFIX.kpathsea}/include \
		--with-kpathsea-libdir=${BUILDLINK_PREFIX.kpathsea}/lib
CONFIGURE_ARGS+=	--with-system-freetype \
		--with-freetype-includes=${BUILDLINK_PREFIX.freetype}/include/freetype \
		--with-freetype-libdir=${BUILDLINK_PREFIX.freetype}/lib

.include "../../graphics/freetype-lib/buildlink3.mk"
.include "../../print/kpathsea/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
