# $NetBSD: Makefile,v 1.52 2016/06/16 04:06:20 markd Exp $

DISTNAME=	texlive-20160523-source
PKGNAME=	web2c-2016
CATEGORIES=	print
MASTER_SITES=	ftp://tug.org/historic/systems/texlive/2016/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://www.tug.org/web2c/
COMMENT=	TeX implementation translating WEB to C

CONFLICTS+=	ja-ptex-bin-[0-9]*
CONFLICTS+=	teTeX-bin<=3.0nb28
CONFLICTS+=	texlive-tetex<2010
DEPENDS+=	kpathsea>=6.2.1:../../print/kpathsea
DEPENDS+=	ptexenc>=1.3.3:../../print/ptexenc

EXTRACT_ELEMENTS=	${DISTNAME}/build-aux \
			${DISTNAME}/texk/web2c

GNU_CONFIGURE=	yes
INFO_FILES=	yes
USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake lex yacc pkg-config
WRKSRC=		${WRKDIR}/${DISTNAME}/texk/web2c

CONFIG_GUESS_OVERRIDE+=	${WRKDIR}/${DISTNAME}/build-aux/config.guess
CONFIG_SUB_OVERRIDE+=	${WRKDIR}/${DISTNAME}/build-aux/config.sub
PKGCONFIG_OVERRIDE=	synctexdir/synctex.pc.in

CONFIGURE_ARGS+=	--disable-luatex
CONFIGURE_ARGS+=	--disable-luajittex
CONFIGURE_ARGS+=	--disable-mflua
CONFIGURE_ARGS+=	--disable-mfluajit
CONFIGURE_ARGS+=	--disable-xetex
CONFIGURE_ARGS+=	--with-x=no
CONFIGURE_ARGS+=	--without-mf-x-toolkit
CONFIGURE_ARGS+=	--with-system-kpathsea
CONFIGURE_ARGS+=	--with-system-libpng
CONFIGURE_ARGS+=	--with-system-cairo
CONFIGURE_ARGS+=	--with-system-gmp \
			--with-gmp-includes=${BUILDLINK_PREFIX.gmp}/include \
			--with-gmp-libdir=${BUILDLINK_PREFIX.gmp}/lib
CONFIGURE_ARGS+=	--with-system-mpfr \
			--with-mpfr-includes=${BUILDLINK_PREFIX.mpfr}/include \
			--with-mpfr-libdir=${BUILDLINK_PREFIX.mpfr}/lib
CONFIGURE_ARGS+=	--with-system-pixman
CONFIGURE_ARGS+=	--with-system-poppler
CONFIGURE_ARGS+=	--with-system-ptexenc
CONFIGURE_ARGS+=	--with-system-xpdf
CONFIGURE_ARGS+=	--with-system-zlib \
			--with-zlib-includes=${BUILDLINK_PREFIX.zlib}/include \
			--with-zlib-libdir=${BUILDLINK_PREFIX.zlib}/lib
LIBTOOL_OVERRIDE=	../*/libtool */libtool

CONFIGURE_DIRS=	${WRKDIR}/${DISTNAME}/texk/web2c
INSTALL_DIRS=	${WRKDIR}/${DISTNAME}/texk/web2c

.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../math/mpfr/buildlink3.mk"
.include "../../print/kpathsea/buildlink3.mk"
.include "../../print/poppler/buildlink3.mk"
.include "../../print/poppler-includes/buildlink3.mk"
.include "../../print/ptexenc/buildlink3.mk"
.include "../../x11/pixman/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
