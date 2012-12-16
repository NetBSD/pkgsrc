# $NetBSD: Makefile,v 1.92 2012/12/16 01:52:26 obache Exp $

DISTNAME=	kdemultimedia-${_KDE_VERSION}
PKGREVISION=	22
CATEGORIES=	multimedia
COMMENT=	Multimedia tools for the KDE integrated X11 desktop

.include "../../meta-pkgs/kde3/Makefile.kde3"

USE_TOOLS+=		pkg-config bash:run

REPLACE_PERL+=		kscd/workman2cddb.pl

REPLACE_BASH+=	kioslave/audiocd/upgrade-metadata.sh \
		kaudiocreator/upgrade-kaudiocreator-metadata.sh

CONF_FILES+=		${PREFIX}/share/examples/kdemultimedia3/applications-merged/kde-multimedia-music.menu \
			${PKG_SYSCONFDIR}/xdg/menus/applications-merged/kde-multimedia-music.menu

.include "../../mk/compiler.mk"
.if !empty(CC_VERSION:Mgcc-3.*)
BUILDLINK_API_DEPENDS.xine-lib+=	xine-lib>=1rc0anb1
.endif

CONFIGURE_ARGS+=	--enable-cdparanoia
CONFIGURE_ARGS+=	--with-cdparanoia=${BUILDLINK_PREFIX.cdparanoia}
CONFIGURE_ARGS+=	--with-vorbis=${BUILDLINK_PREFIX.libvorbis}

.include "options.mk"

# Ensure we export symbols in the linked shared object.
LDFLAGS+=		${EXPORT_SYMBOLS_LDFLAGS}

PTHREAD_OPTS+=	require
PTHREAD_AUTO_VARS=	yes

UNLIMIT_RESOURCES+=	datasize

.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../audio/akode/buildlink3.mk"
.include "../../audio/arts/buildlink3.mk"
.include "../../audio/cdparanoia/buildlink3.mk"
.include "../../audio/flac/buildlink3.mk"
.include "../../audio/lame/buildlink3.mk"
# version 0.5.x is not supported -- reconsider when updating
#.include "../../audio/libtunepimp/buildlink3.mk"
#.include "../../audio/musicbrainz/buildlink3.mk"
.include "../../audio/taglib/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../multimedia/libtheora/buildlink3.mk"
.include "../../multimedia/xine-lib/buildlink3.mk"
.include "../../x11/kdebase3/buildlink3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"

.if defined(PTHREAD_TYPE) && ${PTHREAD_TYPE} == "pth"
.include "../../devel/pthread-sem/buildlink3.mk"
BUILDLINK_TRANSFORM+=	l:pthread:pthread:semaphore
.endif

.include "../../mk/bsd.pkg.mk"
