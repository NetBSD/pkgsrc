# $NetBSD: Makefile,v 1.13 2008/01/04 20:05:11 jmmv Exp $
#

DISTNAME=	bmpx-0.40.13
PKGREVISION=	2
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
CONFIGURE_ARGS+=	--with-boost-regex=mt
CONFIGURE_ARGS+=	--with-boost-filesystem=mt
CONFIGURE_ARGS+=	--with-boost-iostreams=mt
# the following is a fix for nonsense in the configure script
CPPFLAGS+=		-I${LOCALBASE}/include/cdparanoia

CHECK_WRKREF_SKIP=	bin/beep-media-player-2
CHECK_WRKREF_SKIP+=	bin/bmp2
CHECK_WRKREF_SKIP+=	libexec/beep-media-player-2-bin

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
BUILDLINK_API_DEPENDS.librsvg+=	librsvg>=2.14.0
.include "../../devel/libsexymm/buildlink3.mk"
.include "../../graphics/librsvg/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../net/libsoup-devel/buildlink3.mk"
BUILDLINK_API_DEPENDS.gtk2+=		gtk2+>=2.12.0
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
