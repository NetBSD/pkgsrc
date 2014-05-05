# $NetBSD: Makefile,v 1.30 2014/05/05 00:47:37 ryoon Exp $
#

DISTNAME=	mp3splt-gtk-0.8.2
PKGREVISION=	6
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mp3splt/}

MAINTAINER=	schmonz@NetBSD.org
HOMEPAGE=	http://mp3splt.sourceforge.net/
COMMENT=	Utility to split MP3 (VBR supported) and OGG files

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=	 	yes
USE_TOOLS+=		pkg-config msgfmt gmake

LIBS.SunOS+=		-lnsl

.include "options.mk"

CONFIGURE_ARGS+=	--enable-gstreamer
CONFIGURE_ARGS+=	--disable-audacious

.include "../../audio/libmp3splt/buildlink3.mk"
#.include "../../audio/audacious/buildlink3.mk"
.include "../../multimedia/gstreamer0.10/buildlink3.mk"
.include "../../multimedia/gst-plugins0.10-base/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
