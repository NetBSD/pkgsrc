# $NetBSD: Makefile,v 1.27 2003/09/17 23:04:32 markd Exp $

DISTNAME=	kdemultimedia-3.1.4
CATEGORIES=	audio
COMMENT=	Audio tools for the KDE integrated X11 desktop

.include "../../meta-pkgs/kde3/Makefile.kde3"

DEPENDS+=	xanim>=2.80.0:../../graphics/xanim

USE_BUILDLINK2=		YES

REPLACE_PERL=		kscd/workman2cddb.pl

.include "../../mk/bsd.prefs.mk"
.if defined(USE_OSS)
CONFIGURE_ARGS+=	--enable-audio=oss
.endif

CONFIGURE_ARGS+=	--disable-cdparanoia
CONFIGURE_ARGS+=	--with-vorbis=${BUILDLINK_PREFIX.libvorbis}

# Ensure we export symbols in the linked shared object.
LDFLAGS+=		${EXPORT_SYMBOLS_LDFLAGS}

PTHREAD_OPTS+=	require

UNLIMIT_RESOURCES+=	datasize

FOO_MAIN_FILES= \
	kaboodle/kaboodle_main.cpp \
	kmix/kmix_main.cpp \
	kmix/kmixctrl_main.cpp \
	noatun/noatun_main.cpp

.if !exists(${X11BASE}/lib/libXv.so)
PLIST_SUBST+=		XV_WORKAROUND="@comment "
.else
PLIST_SUBST+=		XV_WORKAROUND=""
.endif

.include "../../meta-pkgs/kde3/Makefile.foo_main"

.include "../../audio/arts/buildlink2.mk"
.include "../../graphics/xine-lib/buildlink2.mk"
.include "../../meta-pkgs/kde3/buildlink2.mk"
.include "../../x11/kdebase3/buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/ossaudio.buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
