# $NetBSD: Makefile,v 1.11 2004/04/05 18:41:14 wiz Exp $

DISTNAME=	kdemultimedia-${_KDE_VERSION}
PKGREVISION=	3
CATEGORIES=	multimedia
COMMENT=	Multimedia tools for the KDE integrated X11 desktop

CONFLICTS=	timidity-[0-9]*

.include "../../meta-pkgs/kde3/Makefile.kde3"

DEPENDS+=	xine-arts>=1rc0a:../../audio/xine-arts
DEPENDS+=	trm>=0.2.1:../../audio/trm
DEPENDS+=	xdg-dirs>=1.1:../../misc/xdg-dirs

USE_BUILDLINK2=		YES

REPLACE_PERL=		kscd/workman2cddb.pl

.include "../../mk/compiler.mk"
.if !empty(CC_VERSION:Mgcc-3.*)
BUILDLINK_DEPENDS.xine-lib=	xine-lib>=1rc0anb1
.endif

.if defined(USE_OSS)
CONFIGURE_ARGS+=	--enable-audio=oss
.endif

CONFIGURE_ARGS+=	--disable-cdparanoia
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

.include "../../audio/musicbrainz/buildlink2.mk"
.include "../../audio/taglib/buildlink2.mk"
.include "../../audio/arts/buildlink2.mk"
.include "../../meta-pkgs/kde3/buildlink2.mk"
.include "../../multimedia/xine-lib/buildlink2.mk"
.include "../../x11/kdebase3/buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/ossaudio.buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
