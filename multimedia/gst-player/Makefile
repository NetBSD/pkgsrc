# $NetBSD: Makefile,v 1.3 2004/10/03 00:13:02 tv Exp $

DISTNAME=	gst-player-0.8.0
PKGREVISION=	1
CATEGORIES=	audio graphics
MASTER_SITES=	http://gstreamer.freedesktop.org/src/gst-player/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	benedikt.meurer@unix-ag.uni-siegen.de
HOMEPAGE=	http://www.gstreamer.net/
COMMENT=	GStreamer Media Player

BUILD_USES_MSGFMT=	YES
DEPENDS+=		gst-plugins-mad>=0.8.0:../../audio/gst-plugins-mad
DEPENDS+=		gst-plugins-mpeg2dec>=0.8.0:../../multimedia/gst-plugins-mpeg2dec
DEPENDS+=		gst-plugins-dvdnav>=0.8.0:../../multimedia/gst-plugins-dvdnav
DEPENDS+=		gst-plugins-dvdread>=0.8.0:../../multimedia/gst-plugins-dvdread
DEPENDS+=		gst-plugins-vorbis>=0.8.0:../../audio/gst-plugins-vorbis
DEPENDS+=		gst-plugins-theora>=0.8.0:../../multimedia/gst-plugins-theora

GNU_CONFIGURE=		YES
USE_BUILDLINK3=		YES
USE_DIRS+=		gnome2-1.5
USE_GNU_TOOLS+=		make
USE_LIBTOOL=		YES
USE_PKGLOCALEDIR=	YES
USE_X11=		YES

GCONF2_SCHEMAS=         gst-player.schemas

.include "../../devel/GConf2/schemas.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libbonobo/buildlink3.mk"
.include "../../devel/libglade2/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../multimedia/gst-plugins/buildlink3.mk"
.include "../../multimedia/gstreamer/buildlink3.mk"
.include "../../sysutils/nautilus/buildlink3.mk"
.include "../../textproc/intltool/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
