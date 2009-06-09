# $NetBSD: Makefile,v 1.2 2009/06/09 21:31:04 minskim Exp $

DISTNAME=	texlive-20080816-source
PKGNAME=	xetex-0.999.6
PKGREVISION=	1
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_TEX_CTAN:=systems/texlive/Source/}
EXTRACT_SUFX=	.tar.lzma

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://www.tug.org/xetex/
COMMENT=	TeX system with Unicode and modern font technologies

CONFLICTS+=	web2c<=7.5.7

EXTRACT_ELEMENTS=	${DISTNAME}/config \
			${DISTNAME}/libs/icu-xetex \
			${DISTNAME}/libs/md5 \
			${DISTNAME}/libs/slnunicode \
			${DISTNAME}/libs/xpdf ${DISTNAME}/libs/obsdcompat \
			${DISTNAME}/texk/make \
			${DISTNAME}/texk/config.guess \
			${DISTNAME}/texk/config.sub \
			${DISTNAME}/texk/install.sh \
			${DISTNAME}/texk/mkinstalldirs \
			${DISTNAME}/texk/web2c

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake lex perl yacc
WRKSRC=		${WRKDIR}/${DISTNAME}/texk/web2c

CONFIGURE_ARGS+=	--without-etex --without-omega --without-alepf \
			--without-pdfetex --without-luatex
CONFIGURE_ARGS+=	--with-system-freetype2 \
			--with-freetype2-include=${BUILDLINK_PREFIX.freetype2}/include \
			--with-freetype2-libdir=${BUILDLINK_PREFIX.freetype2}/lib
CONFIGURE_ARGS+=	--with-fontconfig=${BUILDLINK_PREFIX.fontconfig}
CONFIGURE_ARGS+=	--with-system-pnglib \
			--with-pnglib-include=${BUILDLINK_PREFIX.png}/include \
			--with-pnglib-libdir=${BUILDLINK_PREFIX.png}/lib
CONFIGURE_ARGS+=	--with-system-zlib \
			--with-zlib-include=${BUILDLINK_PREFIX.zlib}/include \
			--with-zlib-libdir=${BUILDLINK_PREFIX.zlib}/lib
CONFIGURE_ARGS+=	--enable-static

CONFIGURE_DIRS=	${WRKDIR}/${DISTNAME}/libs/icu-xetex \
		${WRKDIR}/${DISTNAME}/libs/xpdf \
		${WRKDIR}/${DISTNAME}/libs/obsdcompat \
		${WRKDIR}/${DISTNAME}/texk/web2c

MAKE_ENV+=	KPATHSEA_PREFIX=${BUILDLINK_PREFIX.kpathsea}
MAKE_FLAGS+=	LIBTOOL=${LIBTOOL:Q}
MAKE_FLAGS+=	TECKITFLAGS=-I${BUILDLINK_PREFIX.TECkit}/include/teckit \
		LDTECKIT="-L${BUILDLINK_PREFIX.TECkit}/lib -lTECkit" \
		TECKITDEP="" \
		GRAPHITESRCDIR=${BUILDLINK_PREFIX.silgraphite} \
		LDGRAPHITE="-L${BUILDLINK_PREFIX.silgraphite}/lib -lgraphite" \
		GRAPHITEDEP=""

INSTALLATION_DIRS+=	bin

.include "../../converters/TECkit/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/silgraphite/buildlink3.mk"
.include "../../print/kpathsea/buildlink3.mk"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xetex ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
