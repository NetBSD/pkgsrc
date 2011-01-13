# $NetBSD: Makefile,v 1.12 2011/01/13 13:36:30 wiz Exp $
#

DISTNAME=	clutter-gst-1.2.0
PKGREVISION=	2
CATEGORIES=	multimedia
MASTER_SITES=	http://source.clutter-project.org/sources/clutter-gst/1.2/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://www.clutter-project.org/
COMMENT=	Clutter GStreamer integration
LICENSE=	gnu-lgpl-v2.1

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	clutter-gst.pc.in

.include "../../graphics/clutter/buildlink3.mk"
.include "../../multimedia/gstreamer0.10/buildlink3.mk"
.include "../../multimedia/gst-plugins0.10-base/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
