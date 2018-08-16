# $NetBSD: Makefile,v 1.80 2018/08/16 13:56:27 wiz Exp $

DISTNAME=	texlive-20180414-source
PKGNAME=	xetex-0.99999
PKGREVISION=	4
CATEGORIES=	print
MASTER_SITES=	ftp://tug.org/historic/systems/texlive/2018/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://www.tug.org/xetex/
COMMENT=	TeX system with Unicode and modern font technologies

CONFLICTS+=	web2c<=7.5.7
DEPENDS+=	dvipdfmx>=20140525:../../print/dvipdfmx

EXTRACT_ELEMENTS=	${DISTNAME}/build-aux \
			${DISTNAME}/libs/graphite2 \
			${DISTNAME}/libs/harfbuzz \
			${DISTNAME}/libs/xpdf \
			${DISTNAME}/texk/web2c

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c99 c++11
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake lex perl pkg-config yacc
CONFIGURE_ARGS+=	--disable-aleph --disable-etex --disable-pdftex \
			--disable-luatex --disable-mf --disable-mf-nowin \
			--with-x=no \
			--disable-luajittex --disable-luatex53 \
			--disable-mflua --disable-mfluajit \
			--disable-mp --disable-pmp --disable-upmp \
			--disable-ptex --disable-eptex --disable-uptex --disable-euptex \
			--disable-web-progs \
			--enable-web2c --enable-xetex
CONFIGURE_ARGS+=	--with-system-poppler
CONFIGURE_ARGS+= \
	--with-fontconfig-includes=${BUILDLINK_PREFIX.fontconfig}/include \
	--with-fontconfig-libdir=${BUILDLINK_PREFIX.fontconfig}/lib
CONFIGURE_ARGS+=	--with-system-kpathsea
CONFIGURE_ARGS+=	--with-system-zlib \
	--with-zlib-includes=${BUILDLINK_PREFIX.zlib}/include \
	--with-zlib-libdir=${BUILDLINK_PREFIX.zlib}/lib
CONFIGURE_ARGS+=	--with-system-libpng
CONFIGURE_ARGS+=	--with-system-freetype2
CONFIGURE_ARGS+=	--with-system-teckit
CONFIGURE_ARGS+=	--with-system-icu
CONFIGURE_ENV+=		FT2_CONFIG=pkg-config \
			PKG_CONFIG=${TOOLS_CMD.pkg-config}

CONFIGURE_DIRS=		libs/graphite2
CONFIGURE_DIRS+=	libs/harfbuzz
CONFIGURE_DIRS+=	libs/xpdf
CONFIGURE_DIRS+=	texk/web2c

SUBST_CLASSES+=		paths
SUBST_MESSAGE.paths=	Setting paths to commands.
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	texk/web2c/xetexdir/XeTeX_ext.c
SUBST_SED.paths=	-e 's,@XDVIPDFMX@,${LOCALBASE}/bin/xdvipdfmx,g'

INSTALLATION_DIRS+=	bin

CFLAGS.SunOS+=		-D_XOPEN_SOURCE_EXTENDED=0

.include "../../converters/TECkit/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
BUILDLINK_API_DEPENDS.kpathsea+= kpathsea>=6.2.1
.include "../../print/kpathsea/buildlink3.mk"
.include "../../print/poppler/buildlink3.mk"
.include "../../print/poppler-includes/buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/texk/web2c/xetex ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
