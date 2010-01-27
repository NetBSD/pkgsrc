# $NetBSD: Makefile,v 1.161.2.1 2010/01/27 17:40:41 tron Exp $

.include "Makefile.common"

PKGNAME=	ImageMagick-${DISTVERSION}

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://www.imagemagick.org/
COMMENT=	Package for display and interactive manipulation of images

CONFLICTS=	geomview<1.8.1nb2  # used to have a program named 'animate'

PKG_DESTDIR_SUPPORT=	user-destdir
PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LANGUAGES=		c c++ c99
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-openmp
PKGCONFIG_OVERRIDE=	Magick++/lib/ImageMagick++.pc.in
PKGCONFIG_OVERRIDE+=	magick/ImageMagick.pc.in

GCC_REQD+=		2.95.3

PLIST_SUBST+=		IM_MAJOR_VER=${IM_MAJOR_VER:Q}
PLIST_SUBST+=		IM_MAJOR_LIB_VER=${IM_MAJOR_LIB_VER:Q}

TEST_TARGET=		check

.include "options.mk"

.if !empty(MACHINE_PLATFORM:MNetBSD-*-sparc64)
GCC_REQD+=		3.0
.endif

# Avoid compiler bug on "mipsel" (cobalt?)
.if ${MACHINE_ARCH} == "mipsel"
CFLAGS+=		-O
.endif

# Some configure_args come from Makefile.common
CONFIGURE_ARGS+=	--without-perl
CONFIGURE_ARGS+=	--with-ltdl-include=${BUILDLINK_PREFIX.libltdl}/include
CONFIGURE_ARGS+=	--with-ltdl-lib=${BUILDLINK_PREFIX.libltdl}/lib

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/libltdl/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/lcms/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
