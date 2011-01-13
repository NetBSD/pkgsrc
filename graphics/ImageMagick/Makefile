# $NetBSD: Makefile,v 1.168 2011/01/13 13:36:08 wiz Exp $

.include "Makefile.common"

PKGNAME=	ImageMagick-${DISTVERSION}
PKGREVISION=	1

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://www.imagemagick.org/
COMMENT=	Package for display and interactive manipulation of images

CONFLICTS=	geomview<1.8.1nb2  # used to have a program named 'animate'

PKG_DESTDIR_SUPPORT=	user-destdir
PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LANGUAGES=		c c++ c99
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake pkg-config
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-assert
CONFIGURE_ARGS+=	--with-fontconfig
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

# Put our CONFIGURE_ARGS into configure.xml, otherwise WRKDIR gets mentioned.
SUBST_CLASSES+=		fix-cfg
SUBST_STAGE.fix-cfg=	pre-configure
SUBST_MESSAGE.fix-cfg=	Fixing configure.xml.
SUBST_FILES.fix-cfg=	config/configure.xml.in
SUBST_VARS.fix-cfg=	CONFIGURE_ARGS

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/libltdl/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/lcms/buildlink3.mk"
.include "../../graphics/openexr/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../math/fftw/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
