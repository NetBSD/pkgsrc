# $NetBSD: Makefile,v 1.1 2025/12/14 18:16:47 vins Exp $

DISTNAME=	gstreamer1-plugins-sndio-1.24.0
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GITHUB:=BSDKaffee/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/BSDKaffee/gstreamer1-plugins-sndio/
COMMENT=	Sndio audio sink and source for GStreamer
LICENSE=	isc

USE_TOOLS+=	pkg-config

.include "../../multimedia/gst-plugins1-base/buildlink3.mk"
BUILDLINK_DEPMETHOD.gobject-introspection=      build
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../audio/sndio/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
