# $NetBSD: Makefile,v 1.24 2012/09/07 19:16:05 adam Exp $

DISTNAME=		amarok-${VERSION}
VERSION=		1.4.10
PKGREVISION=		24
CATEGORIES=		audio kde
MASTER_SITES=		${MASTER_SITE_KDE:=amarok/${VERSION}/src/}
EXTRACT_SUFX=		.tar.bz2
EXTRACT_USING=		gtar

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://amarok.kde.org/
COMMENT=		KDE3 audio player
LICENSE=		gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		gmake pkg-config msgfmt unzip:run
USE_LANGUAGES=		c c++
GNU_CONFIGURE=		yes
SET_LIBDIR=		yes
USE_LIBTOOL=		yes
RUBY_VERSION_SUPPORTED=	18

CONFIGURE_ARGS+=	--without-nmm
CONFIGURE_ARGS+=	--without-mas
CONFIGURE_ARGS+=	--without-helix
CONFIGURE_ARGS+=	--with-mp4v2
CONFIGURE_ARGS+=	--with-mp4v2-dir=${BUILDLINK_PREFIX.libmp4v2}

LIBS+=			${LIBOSSAUDIO}

PYTHON_PATCH_SCRIPTS= \
	amarok/src/scripts/common/Publisher.py \
	amarok/src/scripts/common/Zeroconf.py \
	amarok/src/scripts/playlist2html/Playlist.py \
	amarok/src/scripts/webcontrol/Playlist.py \
	amarok/src/scripts/playlist2html/PlaylistServer.py \
	amarok/src/scripts/playlist2html/playlist2html.py \
	amarok/src/scripts/templates/python_qt_template.py \
	amarok/src/scripts/webcontrol/Globals.py \
	amarok/src/scripts/playlist2html/Playlist.py \
	amarok/src/scripts/webcontrol/Playlist.py \
	amarok/src/scripts/webcontrol/RequestHandler.py \
	amarok/src/scripts/webcontrol/WebControl.py \
	amarok/src/scripts/webcontrol/WebPublisher.py
REPLACE_RUBY= \
	amarok/src/amarok_proxy.rb \
	amarok/src/mediadevice/daap/amarok_daapserver.rb \
	amarok/src/scripts/lyrics_astraweb/lyrics_astraweb.rb \
	amarok/src/scripts/lyrics_lyrc/lyrics_lyrc.rb \
	amarok/src/scripts/ruby_debug/debug.rb \
	amarok/src/scripts/score_default/score_default.rb \
	amarok/src/scripts/score_impulsive/score_impulsive.rb \
	amarok/src/scripts/templates/amarok.rb \
	amarok/src/scripts/templates/ruby_qt_template.rb

SUBST_CLASSES+=		dotkdedir
SUBST_STAGE.dotkdedir=	post-patch
SUBST_MESSAGE.dotkdedir=Replacing .kde/share with .kde/share/kde
SUBST_FILES.dotkdedir= \
	amarok/src/scripts/playlist2html/Playlist.py \
	amarok/src/scripts/webcontrol/Playlist.py \
	doc/*/config.docbook doc/*/faq.docbook doc/*/advanced.docbook
SUBST_SED.dotkdedir=	-e 's,\.kde/share/,.kde/share/kde/,'

BUILDLINK_API_DEPENDS.kdebase+=	kdebase>=3.3.0
BUILDLINK_API_DEPENDS.kdelibs+=	kdelibs>=3.3.0
BUILDLINK_API_DEPENDS.taglib+=	taglib>=1.4

.include "options.mk"

.include "../../audio/libtunepimp/buildlink3.mk"
.include "../../audio/libvisual/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../audio/taglib/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/ruby/buildlink3.mk"
.include "../../lang/ruby/replace.mk"
.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../multimedia/kdemultimedia3/buildlink3.mk"
.include "../../multimedia/libmp4v2/buildlink3.mk"
.include "../../multimedia/xine-lib/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/kdebase3/buildlink3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
