# $NetBSD: Makefile,v 1.2 2005/02/20 20:41:40 wiz Exp $

DISTNAME=		amarok-1.2
CATEGORIES=		audio kde
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=amarok/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		seb@NetBSD.org
HOMEPAGE=		http://amarok.kde.org/
COMMENT=		KDE audio player

USE_BUILDLINK3=		yes
USE_DIRS+=		xdg-1.1
USE_GNU_TOOLS+=		make
USE_LANGUAGES=		c c++
GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--without-nmm
CONFIGURE_ARGS+=	--without-mas

LIBS+=			${LIBOSSAUDIO}

BUILDLINK_DEPENDS.taglib+=	taglib>=1.3.1
BUILDLINK_DEPENDS.gst-plugins+=	gst-plugins>=0.8.4
BUILDLINK_DEPENDS.gstreamer+=	gstreamer>=0.8.4
BUILDLINK_DEPENDS.arts+=	arts>=1.2

.include "../../audio/arts/buildlink3.mk"
.include "../../audio/libvisual/buildlink3.mk"
.include "../../audio/taglib/buildlink3.mk"
.include "../../audio/tunepimp/buildlink3.mk"
.include "../../audio/xmms/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../mk/ossaudio.buildlink3.mk"
.include "../../multimedia/gst-plugins/buildlink3.mk"
.include "../../multimedia/gstreamer/buildlink3.mk"
.include "../../multimedia/kdemultimedia3/buildlink3.mk"
.include "../../multimedia/xine-lib/buildlink3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
