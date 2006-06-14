# $NetBSD: Makefile,v 1.1.1.1 2006/06/14 10:53:23 drochner Exp $
#

DISTNAME=		gst-ffmpeg-0.10.1
CATEGORIES=		multimedia
MASTER_SITES=		http://gstreamer.freedesktop.org/src/gst-ffmpeg/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://gstreamer.freedesktop.org/src/gst-ffmpeg/
COMMENT=		ffmpeg plugin for gstreamer

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config gmake perl
BUILD_ENV+=		PERL=${PERL5}

.include "../../multimedia/gstreamer0.10/buildlink3.mk"
.include "../../multimedia/gst-plugins0.10-base/buildlink3.mk"
#the bundled one is newer
#.include "../../multimedia/ffmpeg/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
