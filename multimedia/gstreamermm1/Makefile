# $NetBSD: Makefile,v 1.9 2022/06/28 11:34:55 wiz Exp $

DISTNAME=	gstreamermm-1.10.0
PKGREVISION=	8
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gstreamermm/${PKGVERSION_NOREV:R}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://gstreamer.freedesktop.org/bindings/cplusplus.html
COMMENT=	C++ interface for GStreamer
LICENSE=	gnu-lgpl-v2.1

TOOL_DEPENDS+=	libxslt-[0-9]*:../../textproc/libxslt

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

USE_TOOLS+=	gmake pkg-config perl
USE_LANGUAGES=	c c++

CONFIGURE_ARGS+=	--disable-documentation

PKGCONFIG_OVERRIDE+=	gstreamer/gstreamermm.pc.in

.include "../../devel/glibmm/buildlink3.mk"
.include "../../devel/pangomm/buildlink3.mk"
.include "../../graphics/cairomm/buildlink3.mk"
.include "../../multimedia/gstreamer1/buildlink3.mk"
.include "../../multimedia/gst-plugins1-base/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
