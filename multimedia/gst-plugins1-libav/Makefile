# $NetBSD: Makefile,v 1.25 2016/07/09 06:38:39 wiz Exp $

DISTNAME=	gst-libav-1.8.2
PKGNAME=	${DISTNAME:S/gst/gst-plugins1/}
PKGREVISION=	1
CATEGORIES=	multimedia
MASTER_SITES=	http://gstreamer.freedesktop.org/src/gst-libav/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://gstreamer.freedesktop.org/src/gst-libav/
COMMENT=	GStreamer libav/ffmpeg plugin

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config gmake perl
PKGSRC_MAKE_ENV+=	PERL=${PERL5}

#BUILD_DEPENDS+=		yasm>=0.7.2:../../devel/yasm

BUILDLINK_API_DEPENDS.gstreamer1+=	gstreamer1>=1.8.0
.include "../../multimedia/gstreamer1/buildlink3.mk"
.include "../../multimedia/gst-plugins1-base/buildlink3.mk"
# the upstream developers only want to support building against
# the included ffmpeg version, since the ffmpeg API/ABI is unstable
# and there are no releases
.include "../../multimedia/ffmpeg3/buildlink3.mk"
CONFIGURE_ARGS+=	--with-system-libav
.include "../../devel/orc/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
