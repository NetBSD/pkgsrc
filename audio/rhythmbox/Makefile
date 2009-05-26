# $NetBSD: Makefile,v 1.63 2009/05/26 18:15:20 drochner Exp $
#

DISTNAME=	rhythmbox-0.12.1
CATEGORIES=	audio gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/rhythmbox/0.12/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnome.org/projects/rhythmbox/
COMMENT=	Music management application for GNOME

PKG_DESTDIR_SUPPORT=	user-destdir

PKG_OPTIONS_VAR=	rhythmbox
PKG_SUPPORTED_OPTIONS=	hal
PKG_SUGGESTED_OPTIONS=	hal
PLIST_VARS+=		${PKG_SUPPORTED_OPTIONS}

.include "../../mk/bsd.options.mk"

GNU_CONFIGURE=		YES
USE_DIRS+=		gnome2-1.5
USE_TOOLS+=		gmake intltool msgfmt pkg-config
USE_LIBTOOL=		YES
USE_PKGLOCALEDIR=	YES

CONFIGURE_ARGS+=	--disable-browser-plugin
CONFIGURE_ARGS+=	--with-html-dir=${PREFIX}/share/doc
.if !empty(PKG_OPTIONS:Mhal)
CONFIGURE_ARGS+=	--with-ipod
.include "../../audio/libgpod/buildlink3.mk"
# needs a newer libmtp
#CONFIGURE_ARGS+=	--with-mtp
#.include "../../devel/libmtp/buildlink3.mk"
CONFIGURE_ARGS+=	--with-hal
PLIST.hal=		yes
.include "../../sysutils/hal/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-hal
.endif

# for DAAP
.include "../../net/avahi/buildlink3.mk"

GCONF_SCHEMAS=		rhythmbox.schemas

BUILDLINK_API_DEPENDS.gtk2+=		gtk2+>=2.14.0
BUILDLINK_API_DEPENDS.musicbrainz+=	musicbrainz>=2.1.0
BUILDLINK_API_DEPENDS.totem+=		{totem,totem-xine}>=1.1.5

.include "../../lang/python/application.mk"
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../multimedia/py-gstreamer0.10/buildlink3.mk"
.include "../../audio/musicbrainz/buildlink3.mk"
.include "../../devel/GConf/schemas.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../devel/libsexy/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../multimedia/gnome-media/buildlink3.mk"
.include "../../multimedia/gstreamer0.10/buildlink3.mk"
.include "../../multimedia/gst-plugins0.10-base/buildlink3.mk"
.include "../../multimedia/totem-pl-parser/buildlink3.mk"
.include "../../net/libsoup24/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../sysutils/gnome-vfs/buildlink3.mk"
.include "../../sysutils/nautilus-cd-burner/buildlink3.mk"
.include "../../sysutils/libnotify/buildlink3.mk"
.include "../../textproc/gnome-doc-utils/buildlink3.mk"
.include "../../mk/omf-scrollkeeper.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
