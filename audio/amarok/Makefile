# $NetBSD: Makefile,v 1.12 2005/08/30 06:44:37 seb Exp $

DISTNAME=		amarok-1.3
CATEGORIES=		audio kde
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=amarok/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		seb@NetBSD.org
HOMEPAGE=		http://amarok.kde.org/
COMMENT=		KDE audio player

USE_DIRS+=		xdg-1.1
USE_TOOLS+=		gmake pkg-config
USE_LANGUAGES=		c c++
GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--without-nmm
CONFIGURE_ARGS+=	--without-mas

LIBS+=			${LIBOSSAUDIO}

BUILDLINK_DEPENDS.gst-plugins+=	gst-plugins>=0.8.6
BUILDLINK_DEPENDS.gstreamer+=	gstreamer>=0.8.6
BUILDLINK_DEPENDS.kdebase+=	kdebase>=3.3.0
BUILDLINK_DEPENDS.kdelibs+=	kdelibs>=3.3.0
BUILDLINK_DEPENDS.taglib+=	taglib>=1.4

.include "../../audio/arts/buildlink3.mk"
.include "../../audio/libvisual/buildlink3.mk"
.include "../../audio/taglib/buildlink3.mk"
.include "../../audio/tunepimp/buildlink3.mk"
.include "../../audio/xmms/buildlink3.mk"
.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../mk/ossaudio.buildlink3.mk"
.include "../../multimedia/gst-plugins/buildlink3.mk"
.include "../../multimedia/gstreamer/buildlink3.mk"
.include "../../multimedia/kdemultimedia3/buildlink3.mk"
.include "../../multimedia/xine-lib/buildlink3.mk"
.include "../../x11/kdebase3/buildlink3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
