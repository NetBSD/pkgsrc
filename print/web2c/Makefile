# $NetBSD: Makefile,v 1.77 2018/11/14 22:22:20 kleink Exp $

DISTNAME=	texlive-20180414-source
PKGNAME=	web2c-2018
PKGREVISION=	6
CATEGORIES=	print
MASTER_SITES=	ftp://tug.org/historic/systems/texlive/2018/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://www.tug.org/web2c/
COMMENT=	TeX implementation translating WEB to C

DEPENDS+=	kpathsea>=6.2.1:../../print/kpathsea
DEPENDS+=	ptexenc>=1.3.4:../../print/ptexenc

EXTRACT_ELEMENTS=	${DISTNAME}/build-aux \
			${DISTNAME}/texk/web2c

GNU_CONFIGURE=	yes
INFO_FILES=	yes
USE_LANGUAGES=	c c++11
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake lex yacc pkg-config
WRKSRC=		${WRKDIR}/${DISTNAME}/texk/web2c

CONFIG_GUESS_OVERRIDE+=	${WRKDIR}/${DISTNAME}/build-aux/config.guess
CONFIG_SUB_OVERRIDE+=	${WRKDIR}/${DISTNAME}/build-aux/config.sub
PKGCONFIG_OVERRIDE=	synctexdir/synctex.pc.in

CONFIGURE_ARGS+=	--disable-luatex
CONFIGURE_ARGS+=	--disable-luatex53
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
CONFIGURE_ARGS+=	--with-system-xpdf
CONFIGURE_ARGS+=	--with-system-ptexenc
CONFIGURE_ARGS+=	--with-system-zlib \
			--with-zlib-includes=${BUILDLINK_PREFIX.zlib}/include \
			--with-zlib-libdir=${BUILDLINK_PREFIX.zlib}/lib
CONFIGURE_ARGS+=	--with-system-zziplib
LIBTOOL_OVERRIDE=	../*/libtool */libtool

CONFIGURE_DIRS=		${WRKDIR}/${DISTNAME}/texk/web2c
INSTALL_DIRS=	${WRKDIR}/${DISTNAME}/texk/web2c

pre-configure:
	cp ${WRKSRC}/pdftexdir/pdftoepdf-newpoppler.cc  ${WRKSRC}/pdftexdir/pdftoepdf.cc
	cp ${WRKSRC}/pdftexdir/pdftosrc-newpoppler.cc  ${WRKSRC}/pdftexdir/pdftosrc.cc

.include "../../archivers/zziplib/buildlink3.mk"
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
