# $NetBSD: Makefile,v 1.7 2007/08/13 12:06:40 drochner Exp $
#

DISTNAME=	bmpx-0.40.1
CATEGORIES=	audio
MASTER_SITES=	http://files.beep-media-player.org/releases/0.40/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://beep-media-player.org/site/BMPx_Homepage
COMMENT=	Audio player to be used with a frontend or as a daemon

DEPENDS+=	zip-[0-9]*:../../archivers/zip

GNU_CONFIGURE=		yes
USE_DIRS+=		xdg-1.2 kde3-1.0
USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake intltool msgfmt pkg-config
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
CONFIGURE_ENV+=		BOOST_REGEX_LIBS=-lboost_regex-mt
# the following is a fix for nonsense in the configure script
CONFIGURE_ENV+=		SQL3PATH=${BUILDLINK_PREFIX.sqlite3}
CPPFLAGS+=		-I${LOCALBASE}/include/cdparanoia

.include "../../audio/cdparanoia/buildlink3.mk"
.include "../../audio/libofa/buildlink3.mk"
BUILDLINK_API_DEPENDS.taglib+=		taglib>=1.4
.include "../../audio/taglib/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
BUILDLINK_API_DEPENDS.glibmm+=		glibmm>=2.8.3
.include "../../devel/glibmm/buildlink3.mk"
BUILDLINK_API_DEPENDS.libglademm+=	libglademm>=2.6.0
.include "../../devel/libglademm/buildlink3.mk"
BUILDLINK_API_DEPENDS.librsvg2+=	librsvg2>=2.14.0
.include "../../devel/libsexymm/buildlink3.mk"
.include "../../graphics/librsvg2/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../net/libsoup-devel/buildlink3.mk"
BUILDLINK_API_DEPENDS.gtk2+=		gtk2+>=2.10.0
.include "../../x11/gtk2/buildlink3.mk"
BUILDLINK_API_DEPENDS.gtkmm+=		gtkmm>=2.10.0
.include "../../x11/gtkmm/buildlink3.mk"
BUILDLINK_API_DEPENDS.startup-notification+=	startup-notification>=0.8
.include "../../x11/startup-notification/buildlink3.mk"
BUILDLINK_API_DEPENDS.gst-plugins0.10-base+=	gst-plugins0.10-base>=0.10.9
.include "../../multimedia/gst-plugins0.10-base/buildlink3.mk"
BUILDLINK_API_DEPENDS.gstreamer0.10+=		gstreamer0.10>=0.10.11
.include "../../multimedia/gstreamer0.10/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
