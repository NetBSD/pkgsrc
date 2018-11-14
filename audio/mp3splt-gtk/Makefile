# $NetBSD: Makefile,v 1.44 2018/11/14 22:21:04 kleink Exp $
#

DISTNAME=	mp3splt-gtk-0.9.2
PKGREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mp3splt/}

MAINTAINER=	schmonz@NetBSD.org
HOMEPAGE=	http://mp3splt.sourceforge.net/
COMMENT=	Utility to split MP3 (VBR supported) and OGG files
LICENSE=	gnu-gpl-v2

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config msgfmt gmake

LIBS.SunOS+=		-lnsl

CONFIGURE_ARGS+=	--enable-gstreamer
CONFIGURE_ARGS+=	--disable-audacious
CONFIGURE_ARGS+=	--disable-doxygen_doc
CONFIGURE_ARGS+=	--disable-gnome

.include "../../audio/libmp3splt/buildlink3.mk"
.include "../../multimedia/gstreamer1/buildlink3.mk"
.include "../../multimedia/gst-plugins1-base/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
