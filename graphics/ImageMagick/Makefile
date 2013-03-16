# $NetBSD: Makefile,v 1.192 2013/03/16 22:40:25 dholland Exp $

.include "Makefile.common"

PKGNAME=	ImageMagick-${DISTVERSION}
PKGREVISION=	1

MAINTAINER=	adam@NetBSD.org
COMMENT=	Package for display and interactive manipulation of images

CONFLICTS=	geomview<1.8.1nb2  # used to have a program named 'animate'

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LANGUAGES=		c c++ c99
USE_TOOLS+=		gmake pkg-config
CONFIGURE_ARGS+=	--disable-assert
CONFIGURE_ARGS+=	--with-fontconfig
CONFIGURE_ARGS+=	--with-ltdl-include=${BUILDLINK_PREFIX.libltdl}/include
CONFIGURE_ARGS+=	--with-ltdl-lib=${BUILDLINK_PREFIX.libltdl}/lib
CONFIGURE_ARGS+=	--with-xml=yes
CONFIGURE_ARGS+=	--without-perl
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFBASEDIR}
PKGCONFIG_OVERRIDE=	Magick++/lib/ImageMagick++.pc.in
PKGCONFIG_OVERRIDE+=	Magick++/lib/Magick++.pc.in
PKGCONFIG_OVERRIDE+=	magick/ImageMagick.pc.in
PKGCONFIG_OVERRIDE+=	magick/MagickCore.pc.in
PKGCONFIG_OVERRIDE+=	wand/MagickWand.pc.in
PKGCONFIG_OVERRIDE+=	wand/Wand.pc.in

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

PKG_SYSCONFSUBDIR=	ImageMagick
EGDIR=		${PREFIX}/share/examples/ImageMagick
CONF_FILES=	${EGDIR}/coder.xml ${PKG_SYSCONFDIR}/coder.xml
CONF_FILES+=	${EGDIR}/colors.xml ${PKG_SYSCONFDIR}/colors.xml
CONF_FILES+=	${EGDIR}/delegates.xml ${PKG_SYSCONFDIR}/delegates.xml
CONF_FILES+=	${EGDIR}/log.xml ${PKG_SYSCONFDIR}/log.xml
CONF_FILES+=	${EGDIR}/magic.xml ${PKG_SYSCONFDIR}/magic.xml
CONF_FILES+=	${EGDIR}/mime.xml ${PKG_SYSCONFDIR}/mime.xml
CONF_FILES+=	${EGDIR}/policy.xml ${PKG_SYSCONFDIR}/policy.xml
CONF_FILES+=	${EGDIR}/thresholds.xml ${PKG_SYSCONFDIR}/thresholds.xml
CONF_FILES+=	${EGDIR}/type-dejavu.xml ${PKG_SYSCONFDIR}/type-dejavu.xml
CONF_FILES+=	${EGDIR}/type-ghostscript.xml ${PKG_SYSCONFDIR}/type-ghostscript.xml
CONF_FILES+=	${EGDIR}/type-windows.xml ${PKG_SYSCONFDIR}/type-windows.xml
CONF_FILES+=	${EGDIR}/type.xml ${PKG_SYSCONFDIR}/type.xml

SUBST_CLASSES+=		fix-cfg
SUBST_STAGE.fix-cfg=	pre-configure
SUBST_MESSAGE.fix-cfg=	Fixing configure.xml.
SUBST_FILES.fix-cfg=	config/configure.xml.in
SUBST_VARS.fix-cfg=	CONFIGURE_ARGS

SUBST_CLASSES+=		fix-etc
SUBST_STAGE.fix-etc=	pre-configure
SUBST_MESSAGE.fix-etc=	Handle configuration files.
SUBST_FILES.fix-etc=	Makefile.in
SUBST_SED.fix-etc=	-e 's,^configlibdir =.*,configlibdir = $$(DATA_DIR)/examples/ImageMagick,'

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../archivers/xz/buildlink3.mk"
.include "../../devel/libltdl/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/lcms2/buildlink3.mk"
.include "../../graphics/openexr/buildlink3.mk"
.include "../../graphics/libwebp/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../math/fftw/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
