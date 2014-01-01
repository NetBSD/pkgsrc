# $NetBSD: Makefile,v 1.71 2014/01/01 11:52:09 wiz Exp $
#

DISTNAME=		sound-juicer-2.28.2
PKGREVISION=		33
CATEGORIES=		audio
MASTER_SITES=		http://www.burtonini.com/computing/ \
			${MASTER_SITE_GNOME:=sources/sound-juicer/2.28/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.burtonini.com/computing/
COMMENT=		CD ripping tool

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake pkg-config intltool msgfmt
USE_LANGUAGES=		c c++

CONFIGURE_ENV+=		GCONF_SCHEMA_FILE_DIR="${PREFIX}/share/gconf/schemas/"
MAKE_ENV+=		GCONF_SCHEMA_FILE_DIR="${PREFIX}/share/gconf/schemas/"
CONFIGURE_ENV+=		GST_INSPECT="${LOCALBASE}/bin/gst-inspect-0.10"

GCONF_SCHEMAS+=	sound-juicer.schemas

DEPENDS+=	gst-plugins0.10-flac>=0.10.11:../../audio/gst-plugins0.10-flac
DEPENDS+=	gst-plugins0.10-vorbis>=0.10.22:../../audio/gst-plugins0.10-vorbis
DEPENDS+=	gst-plugins0.10-gio>=0.10.21:../../sysutils/gst-plugins0.10-gio

.include "../../audio/libcanberra/buildlink3.mk"
.include "../../audio/libmusicbrainz/buildlink3.mk"
.include "../../audio/taglib/buildlink3.mk"
.include "../../devel/GConf/schemas.mk"
BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.14.0
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libglade/buildlink3.mk"
#.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
BUILDLINK_API_DEPENDS.libcdio+=		libcdio>=0.70
.include "../../misc/libcdio/buildlink3.mk"
BUILDLINK_API_DEPENDS.gstreamer0.10+=	gstreamer0.10>=0.10.15
.include "../../multimedia/gstreamer0.10/buildlink3.mk"
.include "../../multimedia/gst-plugins0.10-base/buildlink3.mk"
.include "../../multimedia/gnome-media/buildlink3.mk"
.include "../../sysutils/brasero/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../mk/omf-scrollkeeper.mk"
.include "../../textproc/gnome-doc-utils/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
BUILDLINK_API_DEPENDS.gtk2+=	gtk2+>=2.12.0
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
