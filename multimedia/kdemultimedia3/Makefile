# $NetBSD: Makefile,v 1.24 2005/03/25 12:25:21 markd Exp $

DISTNAME=	kdemultimedia-${_KDE_VERSION}
CATEGORIES=	multimedia
COMMENT=	Multimedia tools for the KDE integrated X11 desktop

.include "../../meta-pkgs/kde3/Makefile.kde3"

DEPENDS+=	xine-arts>=1rc0a:../../audio/xine-arts

USE_BUILDLINK3=		YES
USE_DIRS+=		xdg-1.1
USE_PKGINSTALL=		YES

REPLACE_PERL=		kscd/workman2cddb.pl

CONF_FILES+=		${PREFIX}/share/examples/kdemultimedia3/applications-merged/kde-multimedia-music.menu \
			${PKG_SYSCONFDIR}/xdg/menus/applications-merged/kde-multimedia-music.menu

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

PKG_OPTIONS_VAR=	PKG_OPTIONS.kdemultimedia
PKG_SUPPORTED_OPTIONS=	gstreamer
.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgstreamer)
.include "../../multimedia/gstreamer/buildlink3.mk"
.include "../../multimedia/gst-plugins/buildlink3.mk"
.endif

# Ensure we export symbols in the linked shared object.
LDFLAGS+=		${EXPORT_SYMBOLS_LDFLAGS}

PTHREAD_OPTS+=	require

UNLIMIT_RESOURCES+=	datasize

.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../audio/arts/buildlink3.mk"
.include "../../audio/cdparanoia/buildlink3.mk"
.include "../../audio/lame/buildlink3.mk"
.include "../../audio/musicbrainz/buildlink3.mk"
.include "../../audio/tunepimp/buildlink3.mk"
.include "../../audio/taglib/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../multimedia/xine-lib/buildlink3.mk"
.include "../../x11/kdebase3/buildlink3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/ossaudio.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
