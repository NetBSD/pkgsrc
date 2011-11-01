# $NetBSD: Makefile,v 1.43 2011/11/01 06:01:25 sbd Exp $
#

.include "Makefile.common"
PKGREVISION=	7
MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.graphicsmagick.org/
COMMENT=	X application for displaying and manipulating images
#LICENSE=	mit AND # see ${WRKSRC}/Copyright.txt

DEPENDS+=	urw-fonts-[0-9]*:../../fonts/urw-fonts

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake pkg-config gs:run
USE_FEATURES=	vsnprintf		# optional but recommended for security
GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=	--with-modules=yes
CONFIGURE_ARGS+=	--enable-shared
CONFIGURE_ARGS+=	--with-gs-font-dir=${URW_FONTS_DIR}/share/fonts/urw

PKGCONFIG_OVERRIDE+=	magick/GraphicsMagick.pc.in \
			wand/GraphicsMagickWand.pc.in \
			Magick++/lib/GraphicsMagick++.pc.in

TEST_TARGET=	check

FIND_PREFIX:=	URW_FONTS_DIR=urw-fonts
.include "../../mk/find-prefix.mk"

.include "options.mk"

CONFIGURE_ARGS+=	--without-perl
CONFIGURE_ARGS+=	--with-ltdl-include=${BUILDLINK_PREFIX.libltdl}/include
CONFIGURE_ARGS+=	--with-ltdl-lib=${BUILDLINK_PREFIX.libltdl}/lib

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/libltdl/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/jbigkit/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/lcms/buildlink3.mk"
.include "../../graphics/libexif/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
