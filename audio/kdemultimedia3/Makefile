# $NetBSD: Makefile,v 1.7 2002/10/07 00:36:34 jlam Exp $

DISTNAME=	kdemultimedia-3.0.3
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

PTHREAD_OPT+=	require

.include "../../audio/arts/buildlink2.mk"
.include "../../x11/kde3/buildlink2.mk"
.include "../../x11/kdebase3/buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/ossaudio.buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
