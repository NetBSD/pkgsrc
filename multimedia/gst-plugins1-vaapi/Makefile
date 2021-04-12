# $NetBSD: Makefile,v 1.4 2021/04/12 13:17:17 nia Exp $

DISTNAME=	gstreamer-vaapi-1.16.2
PKGNAME=	${DISTNAME:S/^gstreamer/gst-plugins1/1}
PKGREVISION=	1
CATEGORIES=	multimedia
MASTER_SITES=	https://gstreamer.freedesktop.org/src/gstreamer-vaapi/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://gstreamer.freedesktop.org/modules/gstreamer-vaapi.html
COMMENT=	Open source multimedia framework - VA-API plugin
LICENSE=	gnu-lgpl-v2.1

USE_TOOLS+=	pkg-config

MESON_ARGS+=	-Ddisable_doc=true

PYTHON_FOR_BUILD_ONLY=	tool

.include "../../devel/meson/build.mk"
.include "../../multimedia/gstreamer1/buildlink3.mk"
.include "../../multimedia/gst-plugins1-bad/buildlink3.mk"
.include "../../multimedia/gst-plugins1-base/buildlink3.mk"
.include "../../multimedia/libva/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
