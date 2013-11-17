# $NetBSD: Makefile,v 1.35 2013/11/17 16:49:24 minskim Exp $

DISTNAME=	texlive-20130530-source
PKGNAME=	web2c-2013
CATEGORIES=	print
MASTER_SITES=	ftp://tug.org/historic/systems/texlive/2013/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://www.tug.org/web2c/
COMMENT=	TeX implementation translating WEB to C

CONFLICTS+=	ja-ptex-bin-[0-9]*
CONFLICTS+=	teTeX-bin<=3.0nb28
CONFLICTS+=	texlive-tetex<2010
DEPENDS+=	kpathsea>=6.1.1:../../print/kpathsea
DEPENDS+=	ptexenc>=1.3.1:../../print/ptexenc

EXTRACT_ELEMENTS=	${DISTNAME}/build-aux \
			${DISTNAME}/texk/web2c

GNU_CONFIGURE=	yes
INFO_FILES=	yes
USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake lex yacc pkg-config
WRKSRC=		${WRKDIR}/${DISTNAME}/texk/web2c

CONFIGURE_ARGS+=	--disable-luatex
CONFIGURE_ARGS+=	--disable-xetex
CONFIGURE_ARGS+=	--with-x=no
CONFIGURE_ARGS+=	--without-mf-x-toolkit
CONFIGURE_ARGS+=	--with-system-kpathsea \
		--with-kpathsea-includes=${BUILDLINK_PREFIX.kpathsea}/include \
		--with-kpathsea-libdir=${BUILDLINK_PREFIX.kpathsea}/lib
CONFIGURE_ARGS+=	--with-system-libpng
CONFIGURE_ARGS+=	--with-system-cairo
CONFIGURE_ARGS+=	--with-system-pixman
CONFIGURE_ARGS+=	--with-system-poppler
CONFIGURE_ARGS+=	--with-system-ptexenc \
		--with-ptexenc-includes=${BUILDLINK_PREFIX.ptexenc}/include \
		--with-ptexenc-libdir=${BUILDLINK_PREFIX.ptexenc}/lib
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
.include "../../print/kpathsea/buildlink3.mk"
.include "../../print/poppler/buildlink3.mk"
.include "../../print/poppler-includes/buildlink3.mk"
.include "../../print/ptexenc/buildlink3.mk"
.include "../../x11/pixman/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
