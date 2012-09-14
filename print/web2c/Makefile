# $NetBSD: Makefile,v 1.26 2012/09/14 12:19:32 drochner Exp $

DISTNAME=	texlive-20120701-source
PKGNAME=	web2c-2012
PKGREVISION=	3
CATEGORIES=	print
MASTER_SITES=	ftp://tug.org/historic/systems/texlive/2012/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://www.tug.org/web2c/
COMMENT=	TeX implementation translating WEB to C

CONFLICTS+=	ja-ptex-bin-[0-9]*
CONFLICTS+=	teTeX-bin<=3.0nb28
CONFLICTS+=	texlive-tetex<2010
DEPENDS+=	kpathsea>=6.0.1:../../print/kpathsea
DEPENDS+=	ptexenc>=1.3.0:../../print/ptexenc

EXTRACT_ELEMENTS=	${DISTNAME}/build-aux \
			${DISTNAME}/libs/obsdcompat \
			${DISTNAME}/texk/web2c

PKG_DESTDIR_SUPPORT=	user-destdir

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
CONFIGURE_ARGS+=	--with-system-libpng \
			--with-libpng-includes=${BUILDLINK_PREFIX.png}/include \
			--with-libpng-libdir=${BUILDLINK_PREFIX.png}/lib
CONFIGURE_ARGS+=	--with-system-ptexenc
CONFIGURE_ARGS+=	--with-system-xpdf
CONFIGURE_ARGS+=	--with-system-zlib \
			--with-zlib-includes=${BUILDLINK_PREFIX.zlib}/include \
			--with-zlib-libdir=${BUILDLINK_PREFIX.zlib}/lib
LIBTOOL_OVERRIDE=	../*/libtool */libtool

CONFIGURE_DIRS=	${WRKDIR}/${DISTNAME}/libs/obsdcompat \
		${WRKDIR}/${DISTNAME}/texk/web2c
INSTALL_DIRS=	${WRKDIR}/${DISTNAME}/texk/web2c

.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../print/kpathsea/buildlink3.mk"
.include "../../print/poppler/buildlink3.mk"
.include "../../print/poppler-includes/buildlink3.mk"
.include "../../print/ptexenc/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
