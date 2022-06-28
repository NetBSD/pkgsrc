# $NetBSD: Makefile,v 1.53 2022/06/28 10:21:56 nia Exp $

DISTNAME=	clutter-gst-3.0.26
PKGREVISION=	8
CATEGORIES=	multimedia gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/clutter-gst/3.0/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://wiki.gnome.org/Projects/Clutter
COMMENT=	Clutter GStreamer integration
LICENSE=	gnu-lgpl-v2.1

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake pkg-config

CONFIGURE_ARGS+=	--enable-introspection=yes

PKGCONFIG_OVERRIDE+=	clutter-gst.pc.in

BUILDLINK_DEPMETHOD.gobject-introspection+=	build
.include "../../devel/gobject-introspection/buildlink3.mk"
BUILDLINK_API_DEPENDS.clutter+=	clutter>=1.6.0
.include "../../graphics/clutter/buildlink3.mk"
.include "../../graphics/cogl/buildlink3.mk"
.include "../../multimedia/gstreamer1/buildlink3.mk"
.include "../../multimedia/gst-plugins1-base/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
