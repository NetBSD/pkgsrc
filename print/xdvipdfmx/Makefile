# $NetBSD: Makefile,v 1.2 2012/07/13 13:44:49 minskim Exp $

DISTNAME=	texlive-20120701-source
PKGNAME=	xdvipdfmx-0.7.8${DISTNAME:C/texlive-([0-9]+)-source/.\1/g}
CATEGORIES=	print converters
MASTER_SITES=	ftp://tug.org/historic/systems/texlive/2012/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	mishka@NetBSD.org
HOMEPAGE=	http://scripts.sil.org/XeTeX
COMMENT=	Extended DVI to PDF converter, mainly for use with XeTeX
LICENSE=	gnu-gpl-v2

DEPENDS+=	dvipdfmx-[0-9]*:../../print/dvipdfmx

EXTRACT_ELEMENTS=	${DISTNAME}/build-aux \
			${DISTNAME}/texk/xdvipdfmx

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
WRKSRC=		${WRKDIR}/${DISTNAME}/texk/xdvipdfmx

CONFIGURE_ARGS+=	--with-system-kpathsea \
		--with-kpathsea-includes=${BUILDLINK_PREFIX.kpathsea}/include \
		--with-kpathsea-libdir=${BUILDLINK_PREFIX.kpathsea}/lib
CONFIGURE_ARGS+=	--with-system-zlib \
		--with-zlib-includes=${BUILDLINK_PREFIX.zlib}/include \
		--with-zlib-libdir=${BUILDLINK_PREFIX.zlib}/lib
CONFIGURE_ARGS+=	--with-system-libpng \
		--with-libpng-includes=${BUILDLINK_PREFIX.png}/include \
		--with-libpng-libdir=${BUILDLINK_PREFIX.png}/lib
CONFIGURE_ARGS+=	--with-system-freetype2 \
		--with-fontconfig-includes=${BUILDLINK_PREFIX.fontconfig}/include \
		--with-fontconfig-libdir=${BUILDLINK_PREFIX.fontconfig}/lib
CONFIGURE_ARGS+=	--with-paper=${BUILDLINK_PREFIX.libpaper}

# At the moment avoid Max OS X specific and use pkgsrc as fonts source
CONFIGURE_ENV+=	kpse_cv_have_ApplicationServices=no

.include "../../devel/zlib/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../print/kpathsea/buildlink3.mk"
.include "../../print/libpaper/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
