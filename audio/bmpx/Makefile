# $NetBSD: Makefile,v 1.1.1.1 2007/02/09 21:04:00 drochner Exp $
#

DISTNAME=	bmpx-0.36.1
CATEGORIES=	audio
MASTER_SITES=	http://files.beep-media-player.org/releases/0.36/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://beep-media-player.org/site/BMPx_Homepage
COMMENT=	Audio player to be used with a frontend or as a daemon

DEPENDS+=	zip-[0-9]*:../../archivers/zip

GNU_CONFIGURE=		yes
USE_DIRS+=		xdg-1.2 kde3-1.0
USE_LANGUAGES=		c c++
USE_TOOLS+=		bison gmake intltool msgfmt pkg-config
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
CONFIGURE_ARGS+=	--enable-mp4v2
CONFIGURE_ARGS+=	--with-mp4v2-dir=${LOCALBASE}
CONFIGURE_ENV+=		BOOST_REGEX_LIBS=-lboost_regex-mt
CPPFLAGS+=		-I${LOCALBASE}/include/cdparanoia

BUILDLINK_API_DEPENDS.cairomm+=		cairomm>=0.6.0
BUILDLINK_API_DEPENDS.glib2+=		glib2>=2.10.0
BUILDLINK_API_DEPENDS.glibmm+=		glibmm>=2.8.3
BUILDLINK_API_DEPENDS.gst-plugins0.10-base+=	gst-plugins0.10-base>=0.10.1
BUILDLINK_API_DEPENDS.gstreamer0.10+=		gstreamer0.10>=0.10.9
BUILDLINK_API_DEPENDS.gtk2+=		gtk2+>=2.4.0
BUILDLINK_API_DEPENDS.gtkmm+=		gtkmm>=2.8.0
BUILDLINK_API_DEPENDS.libglademm+=	libglademm>=2.6.0
BUILDLINK_API_DEPENDS.librsvg2+=	librsvg2>=2.12.6nb1
BUILDLINK_API_DEPENDS.musicbrainz+=	musicbrainz>=2.1.1
BUILDLINK_API_DEPENDS.startup-notification+=	startup-notification>=0.8
BUILDLINK_API_DEPENDS.taglib+=		taglib>=1.4

.include "../../audio/cdparanoia/buildlink3.mk"
.include "../../audio/libofa/buildlink3.mk"
.include "../../audio/taglib/buildlink3.mk"
.include "../../audio/musicbrainz/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/glibmm/buildlink3.mk"
.include "../../devel/libglademm/buildlink3.mk"
.include "../../graphics/cairomm/buildlink3.mk"
.include "../../graphics/librsvg2/buildlink3.mk"
.include "../../multimedia/libmp4v2/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../www/neon/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/gtkmm/buildlink3.mk"
.include "../../x11/startup-notification/buildlink3.mk"
.include "../../mk/fam.buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../multimedia/gst-plugins0.10-base/buildlink3.mk"
.include "../../multimedia/gstreamer0.10/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
