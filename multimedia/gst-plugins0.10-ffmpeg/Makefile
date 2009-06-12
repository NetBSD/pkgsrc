# $NetBSD: Makefile,v 1.11 2009/06/12 17:24:53 ahoka Exp $
#

DISTNAME=		gst-ffmpeg-0.10.3
PKGREVISION=		4
CATEGORIES=		multimedia
MASTER_SITES=		http://gstreamer.freedesktop.org/src/gst-ffmpeg/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://gstreamer.freedesktop.org/src/gst-ffmpeg/
COMMENT=		ffmpeg plugin for gstreamer

PKG_DESTDIR_SUPPORT=	user-destdir

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
OVERRIDE_DIRDEPTH=	3
USE_TOOLS+=		pkg-config gmake perl
PKGSRC_MAKE_ENV+=	PERL=${PERL5}

.include "../../multimedia/gstreamer0.10/buildlink3.mk"
.include "../../multimedia/gst-plugins0.10-base/buildlink3.mk"
# the upstream developers only want to support building against
# the included ffmpeg version, since the ffmpeg API/ABI is unstable
# and there are no releases
#.include "../../multimedia/ffmpeg/buildlink3.mk"
.include "../../devel/liboil/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
