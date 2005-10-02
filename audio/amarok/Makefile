# $NetBSD: Makefile,v 1.15 2005/10/02 15:22:19 seb Exp $

DISTNAME=		amarok-1.3.2
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
CONFIGURE_ARGS+=	--without-arts	# disable aRts engine

LIBS+=			${LIBOSSAUDIO}

BUILDLINK_DEPENDS.gst-plugins+=	gst-plugins>=0.8.6
BUILDLINK_DEPENDS.gstreamer+=	gstreamer>=0.8.6
BUILDLINK_DEPENDS.kdebase+=	kdebase>=3.3.0
BUILDLINK_DEPENDS.kdelibs+=	kdelibs>=3.3.0
BUILDLINK_DEPENDS.taglib+=	taglib>=1.4

# a fix for qt-3.3.5, please remove if qt-3.3.6 (or newer) solves the problem
SUBST_CLASSES+=		hints
SUBST_STAGE.hints=	post-patch
SUBST_MESSAGE.hints=	"Fix includehints."
SUBST_FILES.hints=	amarok/src/DbSetup.ui		\
			amarok/src/Options5.ui		\
			amarok/src/Options7.ui		\
			amarok/src/Options8.ui		\
			amarok/src/firstrunwizard.ui	\
			amarok/src/partydialogbase.ui	\
			amarok/src/tagdialogbase.ui	\
			amarok/src/trackpickerdialogbase.ui
SUBST_FILTER_CMD.hints=	${GREP} -v includehint

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
