# $NetBSD: Makefile,v 1.308 2019/06/18 14:29:20 ryoon Exp $

DISTNAME=	gimp-2.10.12
CATEGORIES=	graphics
MASTER_SITES=	http://download.gimp.org/pub/gimp/v${PKGVERSION_NOREV:R}/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	https://www.gimp.org/
COMMENT=	The GNU image manipulation program
LICENSE=	gnu-lgpl-v3 AND gnu-gpl-v3

BUILD_DEPENDS+=	gdbus-codegen-[0-9]*:../../devel/gdbus-codegen
BUILD_DEPENDS+=	gettext-tools>=0.19:../../devel/gettext-tools
DEPENDS+=	glib-networking>=2.36.2:../../net/glib-networking
CONFLICTS+=	gimp<=1.2.3

USE_LANGUAGES+=		c c++14
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake intltool msgfmt pkg-config
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-perl
CONFIGURE_ARGS+=	--disable-python
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--without-linux-input
CONFIGURE_ARGS+=	--without-mac-twain

PKG_SYSCONFSUBDIR=	gimp/2.0
PKGCONFIG_OVERRIDE=	gimp.pc.in
UNLIMIT_RESOURCES+=	datasize

# GCC 4.x C++14 support is not new enough.
GCC_REQD+=	5.0

.include "../../mk/bsd.prefs.mk"

EGDIR=			${PREFIX}/share/examples/gimp-2.0
.for f in controllerrc gimprc gtkrc menurc sessionrc templaterc unitrc
CONF_FILES+=		${EGDIR}/${f} ${PKG_SYSCONFDIR}/${f}
.endfor

# Ensure we export symbols in the linked shared object.
LDFLAGS+=		${EXPORT_SYMBOLS_LDFLAGS}

PLIST_VARS+=		remote
.if ${OPSYS} == "Darwin"
PLIST_SUBST+=  GIMP_DEBUG_TOOL_DIR="bin"
.else
PLIST_SUBST+=  GIMP_DEBUG_TOOL_DIR="libexec"
.endif

.include "options.mk"

BUILDLINK_API_DEPENDS.freetype2+=	freetype2>=2.8.1
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../databases/shared-mime-info/mimedb.mk"
.include "../../archivers/xz/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
BUILDLINK_API_DEPENDS.fontconfig+=	fontconfig>=2.12.4
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
BUILDLINK_API_DEPENDS.babl+=		babl>=0.1.50
.include "../../graphics/babl/buildlink3.mk"
BUILDLINK_API_DEPENDS.gegl+=		gegl>=0.4.2
.include "../../graphics/gegl/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/gexiv2/buildlink3.mk"
.include "../../graphics/jasper/buildlink3.mk"
.include "../../graphics/lcms2/buildlink3.mk"
.include "../../graphics/libart/buildlink3.mk"
.include "../../graphics/libexif/buildlink3.mk"
.include "../../graphics/libmypaint/buildlink3.mk"
.include "../../graphics/mypaint-brushes/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/librsvg/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../graphics/libwmf/buildlink3.mk"
.include "../../print/poppler-data/buildlink3.mk"
.include "../../print/poppler-glib/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.if !empty(PKG_BUILD_OPTIONS.gtk2:Mx11)
PLIST.remote=	yes
.include "../../x11/libICE/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-xmc
CONFIGURE_ARGS+=	--without-libxpm
.endif
.if !empty(PKG_BUILD_OPTIONS.gtk2:Mquartz)
.include "../../x11/gtk-mac-integration/buildlink3.mk"
.endif
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
