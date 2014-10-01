# $NetBSD: Makefile,v 1.2 2014/10/01 14:26:15 wiz Exp $

DISTNAME=	gst-rtsp-server-1.4.3
CATEGORIES=	net multimedia
MASTER_SITES=	http://gstreamer.freedesktop.org/src/gst-rtsp-server/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://gstreamer.freedesktop.org/src/gst-rtsp-server/
COMMENT=	GStreamer RTSP server

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config gmake
PKGCONFIG_OVERRIDE=	gstreamer-rtsp-server.pc.in

BUILDLINK_API_DEPENDS.gstreamer1+=	gstreamer1>=1.2.0
.include "../../multimedia/gstreamer1/buildlink3.mk"
.include "../../multimedia/gst-plugins1-base/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
