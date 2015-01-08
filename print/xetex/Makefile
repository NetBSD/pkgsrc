# $NetBSD: Makefile,v 1.34 2015/01/08 10:20:37 wiz Exp $

DISTNAME=	texlive-20130530-source
PKGNAME=	xetex-0.9999.3
PKGREVISION=	7
CATEGORIES=	print
MASTER_SITES=	ftp://tug.org/historic/systems/texlive/2013/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://www.tug.org/xetex/
COMMENT=	TeX system with Unicode and modern font technologies

CONFLICTS+=	web2c<=7.5.7
DEPENDS+=	xdvipdfmx-[0-9]*:../../print/xdvipdfmx

EXTRACT_ELEMENTS=	${DISTNAME}/build-aux \
			${DISTNAME}/libs/graphite2 \
			${DISTNAME}/libs/harfbuzz \
			${DISTNAME}/libs/xpdf \
			${DISTNAME}/texk/web2c

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake lex perl pkg-config yacc
CONFIGURE_ARGS+=	--disable-aleph --disable-etex --disable-pdftex \
			--disable-luatex --disable-mf --disable-mf-nowin \
			--disable-mp \
			--disable-ptex --disable-eptex --disable-uptex --disable-euptex \
			--disable-web-progs \
			--enable-web2c --enable-xetex
CONFIGURE_ARGS+=	--with-system-poppler
CONFIGURE_ARGS+= \
	--with-fontconfig-includes=${BUILDLINK_PREFIX.fontconfig}/include \
	--with-fontconfig-libdir=${BUILDLINK_PREFIX.fontconfig}/lib
CONFIGURE_ARGS+=	--with-system-kpathsea \
	--with-kpathsea-includes=${BUILDLINK_PREFIX.kpathsea}/include \
	--with-kpathsea-libdir=${BUILDLINK_PREFIX.kpathsea}/lib
CONFIGURE_ARGS+=	--with-system-zlib \
	--with-zlib-includes=${BUILDLINK_PREFIX.zlib}/include \
	--with-zlib-libdir=${BUILDLINK_PREFIX.zlib}/lib
CONFIGURE_ARGS+=	--with-system-libpng
CONFIGURE_ARGS+=	--with-system-freetype2
CONFIGURE_ARGS+=	--with-system-teckit \
	--with-teckit-includes=${BUILDLINK_PREFIX.TECkit}/include/teckit \
	--with-teckit-libdir=${BUILDLINK_PREFIX.TECkit}/lib
CONFIGURE_ARGS+=	--with-system-icu

CONFIGURE_DIRS=		libs/graphite2
CONFIGURE_DIRS+=	libs/harfbuzz
CONFIGURE_DIRS+=	libs/xpdf
CONFIGURE_DIRS+=	texk/web2c

EVAL_PREFIX+=	XDVIPDFMX_PREFIX=xdvipdfmx

SUBST_CLASSES+=		paths
SUBST_MESSAGE.paths=	Setting paths to commands.
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	texk/web2c/xetexdir/XeTeX_ext.c
SUBST_SED.paths=	-e 's,@XDVIPDFMX@,${XDVIPDFMX_PREFIX}/bin/xdvipdfmx,g'

INSTALLATION_DIRS+=	bin

CFLAGS.SunOS+= -std=gnu99 -D_XOPEN_SOURCE_EXTENDED=0

.include "../../converters/TECkit/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../print/kpathsea/buildlink3.mk"
.include "../../print/poppler/buildlink3.mk"
.include "../../print/poppler-includes/buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/texk/web2c/xetex ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
