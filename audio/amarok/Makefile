# $NetBSD: Makefile,v 1.202 2024/05/29 16:31:18 adam Exp $

DISTNAME=	amarok-3.0.0
PKGREVISION=	1
CATEGORIES=	audio multimedia
MASTER_SITES=	${MASTER_SITE_KDE:=amarok/${PKGVERSION_NOREV}/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://amarok.kde.org/
COMMENT=	KDE audio player
LICENSE=	gnu-gpl-v2 AND gnu-fdl-v1.2 AND gnu-lgpl-v2.1

.include "../../meta-pkgs/kde/applications.mk"

USE_TOOLS+=	msgfmt pkg-config perl:run

REPLACE_PERL+=	src/kconf_update/amarok-2.4.1-tokens_syntax_update.pl

#MYSQL_VERSIONS_ACCEPTED=	mariadb1011 mariadb106 mariadb105 mariadb104

CONF_FILES+=	share/examples/amarok/xdg/amarok_homerc ${PKG_SYSCONFDIR}/xdg/amarok_homerc
MAKE_DIRS+=	${PKG_SYSCONFDIR}/xdg

INSTALLATION_DIRS+=	share/examples/amarok/xdg

post-install:
	${MV} ${DESTDIR}${PKG_SYSCONFDIR}/xdg/amarok_homerc ${DESTDIR}${PREFIX}/share/examples/amarok/xdg

# add options for these?
# * Taglib-Extras
# * LibLastFm, Enable Last.Fm service, including scrobbling, song submissions, and suggested song dynamic playlists, <http://cdn.last.fm/client/liblastfm-1.0.3.tar.gz>
# * FFmpeg, Libraries and tools for handling multimedia data, <https://www.ffmpeg.org/>
#   Enable MusicDNS service
# * LibOFA, Open-source audio fingerprint by MusicIP, <http://code.google.com/p/musicip-libofa/>
#   Enable MusicDNS service
# * Mygpo-qt5 (required version >= 1.1.0), A Qt/C++ library wrapping the gpodder.net Webservice., <http://wiki.gpodder.org/wiki/Libmygpo-qt>
#   Synchronize podcast subscriptions with gpodder.net
# * Ipod, Support Apple iPod/iPad/iPhone audio devices, <http://sourceforge.net/projects/gtkpod/>
# * Loudmouth, Loudmouth is the communication backend needed by mp3tunes for syncing., <http://www.loudmouth-project.org>

.include "../../archivers/karchive/buildlink3.mk"
.include "../../audio/taglib/buildlink3.mk"
.include "../../databases/mariadb1011-embedded/buildlink3.mk"
.include "../../devel/googletest/buildlink3.mk"
.include "../../devel/kcmutils/buildlink3.mk"
.include "../../devel/kconfig/buildlink3.mk"
.include "../../devel/kcoreaddons/buildlink3.mk"
.include "../../devel/kcrash/buildlink3.mk"
.include "../../devel/kdeclarative/buildlink3.mk"
.include "../../devel/kdoctools/buildlink3.mk"
.include "../../devel/ki18n/buildlink3.mk"
.include "../../devel/kio/buildlink3.mk"
.include "../../devel/knotifications/buildlink3.mk"
.include "../../devel/kpackage/buildlink3.mk"
.include "../../devel/ktexteditor/buildlink3.mk"
.include "../../devel/libmtp/buildlink3.mk"
.include "../../devel/threadweaver/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/kiconthemes/buildlink3.mk"
.include "../../math/fftw/buildlink3.mk"
.include "../../misc/attica-qt5/buildlink3.mk"
.include "../../net/kdnssd/buildlink3.mk"
.include "../../net/knewstuff/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../sysutils/kdbusaddons/buildlink3.mk"
.include "../../sysutils/solid/buildlink3.mk"
.include "../../textproc/kcodecs/buildlink3.mk"
.include "../../x11/kconfigwidgets/buildlink3.mk"
.include "../../x11/kglobalaccel/buildlink3.mk"
.include "../../x11/kguiaddons/buildlink3.mk"
.include "../../x11/kwidgetsaddons/buildlink3.mk"
.include "../../x11/kwindowsystem/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtdeclarative/buildlink3.mk"
.include "../../x11/qt5-qtsvg/buildlink3.mk"
.include "../../x11/qt5-qtwebengine/buildlink3.mk"
#.include "../../mk/mysql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
