# $NetBSD: Makefile,v 1.20 2012/09/15 10:05:53 obache Exp $
#

DISTNAME=		subtitleeditor-0.30.0
PKGREVISION=		12
CATEGORIES=		multimedia
MASTER_SITES=		http://download.gna.org/subtitleeditor/0.30/

MAINTAINER=		ccatrian@eml.cc
HOMEPAGE=		http://home.gna.org/subtitleeditor/
COMMENT=		GTK+2 tool to edit movie subtitles

PKG_DESTDIR_SUPPORT=	user-destdir

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake intltool pkg-config msgfmt
GNU_CONFIGURE=		yes
USE_LANGUAGES=		c c++

BUILDLINK_API_DEPENDS.glibmm+=	glibmm>=2.16.3
.include "../../devel/glibmm/buildlink3.mk"
.include "../../devel/libglademm/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../multimedia/gstreamer0.10/buildlink3.mk"
.include "../../multimedia/gst-plugins0.10-base/buildlink3.mk"
.include "../../multimedia/gst-plugins0.10-good/buildlink3.mk"
.include "../../textproc/enchant/buildlink3.mk"
.include "../../textproc/iso-codes/buildlink3.mk"
.include "../../textproc/libxml++/buildlink3.mk"
BUILDLINK_API_DEPENDS.gtkmm+=	gtkmm>=2.12
.include "../../x11/gtkmm/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"

.include "../../mk/bsd.pkg.mk"
