# $NetBSD: Makefile,v 1.7 2013/12/04 11:35:56 drochner Exp $
#

DISTNAME=	gst-libav-1.0.10
CATEGORIES=	multimedia
MASTER_SITES=	http://gstreamer.freedesktop.org/src/gst-libav/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://gstreamer.freedesktop.org/src/gst-libav/
COMMENT=	GStreamer libav/ffmpeg plugin

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
#OVERRIDE_DIRDEPTH=	3
USE_TOOLS+=		pkg-config gmake perl
PKGSRC_MAKE_ENV+=	PERL=${PERL5}

#BUILD_DEPENDS+=		yasm>=0.7.2:../../devel/yasm

.include "../../multimedia/gstreamer1/buildlink3.mk"
.include "../../multimedia/gst-plugins1-base/buildlink3.mk"
# the upstream developers only want to support building against
# the included ffmpeg version, since the ffmpeg API/ABI is unstable
# and there are no releases
.include "../../multimedia/ffmpeg010/buildlink3.mk"
CONFIGURE_ARGS+=	--with-system-libav
.include "../../devel/orc/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
