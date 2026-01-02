# $NetBSD: Makefile,v 1.2 2026/01/02 09:16:11 vins Exp $

DISTNAME=	gstreamer1-plugins-sndio-1.24.0
PKGNAME=	${DISTNAME:S/gstreamer1-plugins/gst-plugins1/}
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GITHUB:=BSDKaffee/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/BSDKaffee/gstreamer1-plugins-sndio/
COMMENT=	Sndio audio sink and source for GStreamer
LICENSE=	isc

USE_TOOLS+=	pkg-config

WRKSRC=		${WRKDIR}/${DISTNAME}

.include "../../multimedia/gst-plugins1-base/buildlink3.mk"
BUILDLINK_DEPMETHOD.gobject-introspection=      build
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../audio/sndio/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
