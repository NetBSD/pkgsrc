# $NetBSD: Makefile,v 1.12.2.1 2003/03/02 10:35:00 agc Exp $

DISTNAME=	kdemultimedia-3.0.5a
CATEGORIES=	audio
COMMENT=	Audio tools for the KDE integrated X11 desktop

.include "../../x11/kde3/Makefile.kde3"

DEPENDS+=	xanim>=2.80.0:../../graphics/xanim

USE_BUILDLINK2=		YES

.include "../../mk/bsd.prefs.mk"
.if defined(USE_OSS)
CONFIGURE_ARGS+=	--enable-audio=oss
.endif

# Ensure we export symbols in the linked shared object.
LDFLAGS+=		${EXPORT_SYMBOLS_LDFLAGS}

PTHREAD_OPTS+=	require

UNLIMIT_RESOURCES+=	datasize

FOO_MAIN_FILES= \
	kaboodle/kaboodle_main.cpp \
	kmix/kmix_main.cpp \
	kmix/kmixctrl_main.cpp \
	noatun/noatun_main.cpp

.include "../../x11/kde3/Makefile.foo_main"

.include "../../audio/arts/buildlink2.mk"
.include "../../x11/kde3/buildlink2.mk"
.include "../../x11/kdebase3/buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/ossaudio.buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
