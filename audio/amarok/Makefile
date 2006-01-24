# $NetBSD: Makefile,v 1.28 2006/01/24 07:31:53 wiz Exp $

DISTNAME=		amarok-1.3.8
PKGREVISION=		1
CATEGORIES=		audio kde
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=amarok/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		wiz@NetBSD.org
HOMEPAGE=		http://amarok.kde.org/
COMMENT=		KDE audio player

USE_DIRS+=		xdg-1.1
USE_TOOLS+=		gmake pkg-config
USE_LANGUAGES=		c c++
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes

CONFIGURE_ARGS+=	--without-nmm
CONFIGURE_ARGS+=	--without-mas
CONFIGURE_ARGS+=	--without-helix
CONFIGURE_ARGS+=	--without-arts	# disable aRts engine

LIBS+=			${LIBOSSAUDIO}

BUILDLINK_DEPENDS.kdebase+=	kdebase>=3.3.0
BUILDLINK_DEPENDS.kdelibs+=	kdelibs>=3.3.0
BUILDLINK_DEPENDS.taglib+=	taglib>=1.4

.include "../../audio/libvisual/buildlink3.mk"
.include "../../audio/taglib/buildlink3.mk"
.include "../../audio/tunepimp/buildlink3.mk"
.include "../../audio/xmms/buildlink3.mk"
.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../mk/ossaudio.buildlink3.mk"
.include "../../multimedia/gst-plugins0.8/buildlink3.mk"
.include "../../multimedia/gstreamer0.8/buildlink3.mk"
.include "../../multimedia/kdemultimedia3/buildlink3.mk"
.include "../../multimedia/xine-lib/buildlink3.mk"
.include "../../x11/kdebase3/buildlink3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
