# $NetBSD: Makefile,v 1.13 2004/04/20 13:13:42 markd Exp $

DISTNAME=	kdemultimedia-${_KDE_VERSION}
CATEGORIES=	multimedia
COMMENT=	Multimedia tools for the KDE integrated X11 desktop

CONFLICTS=	timidity-[0-9]*

.include "../../meta-pkgs/kde3/Makefile.kde3"

DEPENDS+=	xine-arts>=1rc0a:../../audio/xine-arts
DEPENDS+=	trm>=0.2.1:../../audio/trm

USE_BUILDLINK3=		YES
USE_DIRS+=		xdg-1.1

REPLACE_PERL=		kscd/workman2cddb.pl

.include "../../mk/compiler.mk"
.if !empty(CC_VERSION:Mgcc-3.*)
BUILDLINK_DEPENDS.xine-lib=	xine-lib>=1rc0anb1
.endif

.if defined(USE_OSS)
CONFIGURE_ARGS+=	--enable-audio=oss
.endif

CONFIGURE_ARGS+=	--enable-cdparanoia
CONFIGURE_ARGS+=	--with-cdparanoia=${BUILDLINK_PREFIX.cdparanoia}
CONFIGURE_ARGS+=	--with-vorbis=${BUILDLINK_PREFIX.libvorbis}

# Ensure we export symbols in the linked shared object.
LDFLAGS+=		${EXPORT_SYMBOLS_LDFLAGS}

PTHREAD_OPTS+=	require

UNLIMIT_RESOURCES+=	datasize

.if !exists(${X11BASE}/lib/libXv.so)
PLIST_SUBST+=		XV_WORKAROUND="@comment "
PLIST_SUBST+=		XV_SUFFIX="a"
.else
PLIST_SUBST+=		XV_WORKAROUND=""
PLIST_SUBST+=		XV_SUFFIX="so"
.endif

.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../audio/arts/buildlink3.mk"
.include "../../audio/cdparanoia/buildlink3.mk"
.include "../../audio/musicbrainz/buildlink3.mk"
.include "../../audio/taglib/buildlink3.mk"
.include "../../multimedia/xine-lib/buildlink3.mk"
.include "../../x11/kdebase3/buildlink3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/ossaudio.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
