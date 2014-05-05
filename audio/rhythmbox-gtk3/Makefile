# $NetBSD: Makefile,v 1.20 2014/05/05 00:47:38 ryoon Exp $

DISTNAME=	rhythmbox-3.0.1
PKGREVISION=	2
CATEGORIES=	audio gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/rhythmbox/${PKGVERSION_NOREV:R}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnome.org/projects/rhythmbox/
COMMENT=	Music management application for GNOME
LICENSE=	gnu-gpl-v2 # with exception for non-GPL GStreamer plugins

GNU_CONFIGURE=		YES
USE_TOOLS+=		gmake intltool msgfmt pkg-config
USE_LIBTOOL=		YES
USE_PKGLOCALEDIR=	YES

BUILD_DEPENDS+=		itstool-[0-9]*:../../textproc/itstool

CONFIGURE_ARGS+=	--disable-browser-plugin
CONFIGURE_ARGS+=	--with-html-dir=${PREFIX}/share/doc
CONFIGURE_ARGS+=	--disable-fm-radio

PYTHON_VERSIONS_INCOMPATIBLE=	26 27

# option?
.include "../../net/grilo/buildlink3.mk"

.include "../../devel/glib2/schemas.mk"
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../devel/libpeas/buildlink3.mk"
.include "../../databases/tdb/buildlink3.mk"
.include "../../textproc/json-glib/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
# needs introspection support
BUILDLINK_API_DEPENDS.gstreamer1+=  gstreamer1>=1.0.6
BUILDLINK_API_DEPENDS.gst-plugins1-base+= gst-plugins1-base>=1.0.6
.include "../../multimedia/gstreamer1/buildlink3.mk"
.include "../../multimedia/gst-plugins1-base/buildlink3.mk"
BUILDLINK_API_DEPENDS.totem-pl-parser+= totem-pl-parser>=3.2.0
.include "../../multimedia/totem-pl-parser/buildlink3.mk"
.include "../../net/libsoup24/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
