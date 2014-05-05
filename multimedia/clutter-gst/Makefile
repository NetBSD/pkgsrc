# $NetBSD: Makefile,v 1.33 2014/05/05 00:48:10 ryoon Exp $
#

DISTNAME=	clutter-gst-2.0.8
PKGREVISION=	1
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/clutter-gst/2.0/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.clutter-project.org/
COMMENT=	Clutter GStreamer integration
LICENSE=	gnu-lgpl-v2.1

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake pkg-config

PKGCONFIG_OVERRIDE+=	clutter-gst.pc.in

.include "options.mk"

BUILDLINK_API_DEPENDS.clutter+=	clutter>=1.6.0
.include "../../graphics/clutter/buildlink3.mk"
.include "../../graphics/cogl/buildlink3.mk"
.include "../../multimedia/gstreamer1/buildlink3.mk"
.include "../../multimedia/gst-plugins1-base/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
