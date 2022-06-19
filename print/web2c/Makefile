# $NetBSD: Makefile,v 1.110 2022/06/19 20:05:15 spz Exp $

.include "../../print/texlive/Makefile.common"

PKGNAME=	web2c-2022
CATEGORIES=	print

HOMEPAGE=	https://www.tug.org/web2c/
COMMENT=	TeX implementation translating WEB to C

DEPENDS+=	kpathsea>=6.2.1:../../print/kpathsea
DEPENDS+=	ptexenc>=1.4.0:../../print/ptexenc

EXTRACT_ELEMENTS+=	${DISTNAME}/libs/xpdf
EXTRACT_ELEMENTS+=	${DISTNAME}/texk/web2c

USE_LANGUAGES=		c c++14
USE_TOOLS+=		gmake lex yacc
GNU_CONFIGURE_STRICT=	no # texk/web2c/web2c doesn't know the options
PKGCONFIG_OVERRIDE=	synctexdir/synctex.pc.in

# C++14
GCC_REQD+=		5

INFO_FILES=		yes
WRKSRC=			${WRKDIR}/${DISTNAME}/texk/web2c

#CXXFLAGS+=		-fpermissive

CONFIGURE_ENV+=		enable_texlive_build=yes
CONFIGURE_ARGS+=	--with-banner-add="/pkgsrc"
CONFIGURE_ARGS+=	--disable-luatex
CONFIGURE_ARGS+=	--disable-luahbtex
CONFIGURE_ARGS+=	--disable-luatex53
CONFIGURE_ARGS+=	--disable-luajittex
CONFIGURE_ARGS+=	--disable-luajithbtex
CONFIGURE_ARGS+=	--disable-mflua
CONFIGURE_ARGS+=	--disable-mfluajit
CONFIGURE_ARGS+=	--disable-xetex
CONFIGURE_ARGS+=	--with-x=no
CONFIGURE_ARGS+=	--without-mf-x-toolkit
CONFIGURE_ARGS+=	--with-system-kpathsea
CONFIGURE_ARGS+=	--with-system-libpng
CONFIGURE_ARGS+=	--with-system-cairo
CONFIGURE_ARGS+=	--with-system-gmp
CONFIGURE_ARGS+=	--with-gmp-includes=${BUILDLINK_PREFIX.gmp}/include
CONFIGURE_ARGS+=	--with-gmp-libdir=${BUILDLINK_PREFIX.gmp}/lib
CONFIGURE_ARGS+=	--with-system-mpfr
CONFIGURE_ARGS+=	--with-mpfr-includes=${BUILDLINK_PREFIX.mpfr}/include
CONFIGURE_ARGS+=	--with-mpfr-libdir=${BUILDLINK_PREFIX.mpfr}/lib
CONFIGURE_ARGS+=	--with-system-pixman
CONFIGURE_ARGS+=	--with-system-ptexenc
CONFIGURE_ARGS+=	--with-system-zlib
CONFIGURE_ARGS+=	--with-zlib-includes=${BUILDLINK_PREFIX.zlib}/include
CONFIGURE_ARGS+=	--with-zlib-libdir=${BUILDLINK_PREFIX.zlib}/lib
CONFIGURE_ARGS+=	--with-system-zziplib
LIBTOOL_OVERRIDE=	../*/libtool */libtool

CONFIGURE_DIRS=		${WRKDIR}/${DISTNAME}/libs/xpdf
CONFIGURE_DIRS+=	${WRKDIR}/${DISTNAME}/texk/web2c
INSTALL_DIRS=		${WRKDIR}/${DISTNAME}/texk/web2c

.include "../../archivers/zziplib/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../math/mpfr/buildlink3.mk"
.include "../../print/kpathsea/buildlink3.mk"
.include "../../print/ptexenc/buildlink3.mk"
.include "../../x11/pixman/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
