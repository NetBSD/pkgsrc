# $NetBSD: Makefile,v 1.19 2012/09/11 23:59:27 asau Exp $
#

DISTNAME=	buzztard-0.5.0
PKGREVISION=	15
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=buzztard/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://buzztard.sourceforge.net/
COMMENT=	Modular, free, open source music studio
LICENSE=	gnu-gpl-v3 AND gnu-fdl-v1.1

BUILD_DEPENDS+=	libxslt-[0-9]*:../../textproc/libxslt
BUILD_DEPENDS+=	aspell-[0-9]*:../../textproc/aspell

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake intltool pkg-config msgfmt msgmerge xgettext

PKGCONFIG_OVERRIDE+=	src/lib/ic/libbuzztard-ic.pc.in
PKGCONFIG_OVERRIDE+=	src/lib/core/libbuzztard-core.pc.in

#PKG_CHECK_MODULES(HILDON_DEPS, hildon-libs libosso, [
#PKG_CHECK_MODULES(GOBJECT_INTROSPECTION, [gobject-introspection-1.0],[

.include "../../audio/bml/buildlink3.mk"
.include "../../audio/gst-buzztard/buildlink3.mk"
.include "../../databases/shared-mime-info/mimedb.mk"
.include "../../devel/GConf/schemas.mk"
BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.10.0
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libgnome/buildlink3.mk"
.include "../../devel/libgsf/buildlink3.mk"
.include "../../graphics/gnome-icon-theme/buildlink3.mk"
BUILDLINK_API_DEPENDS.gnome-vfs+=	gnome-vfs>=2.10.0
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/gnome-icon-theme/buildlink3.mk"
.include "../../graphics/libgnomecanvas/buildlink3.mk"
.include "../../graphics/librsvg/buildlink3.mk"
BUILDLINK_API_DEPENDS.gst-plugins0.10-base+=	gst-plugins0.10-base>=0.10.7
.include "../../multimedia/gst-plugins0.10-base/buildlink3.mk"
BUILDLINK_API_DEPENDS.gstreamer0.10+=	gstreamer0.10>=0.10.7
.include "../../multimedia/gstreamer0.10/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../sysutils/gnome-vfs/buildlink3.mk"
.include "../../sysutils/hal/buildlink3.mk"
.include "../../textproc/gtk-doc/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/omf-scrollkeeper.mk"
BUILDLINK_API_DEPENDS.gtk2+=	gtk2+>=2.6.0
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
