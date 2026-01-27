# $NetBSD: Makefile,v 1.174 2026/01/27 08:40:35 wiz Exp $

DISTNAME=	k3b-${KAPPSVER}
PKGREVISION=	3
CATEGORIES=	sysutils

HOMEPAGE=	https://userbase.kde.org/K3b
COMMENT=	DVD and CD authoring program
LICENSE=	gnu-gpl-v2 AND gnu-fdl-v1.2

.include "../../meta-pkgs/kde/applications.mk"

TOOL_DEPENDS+=	kf6-kdoctools>=6.18.0:../../devel/kf6-kdoctools
DEPENDS+=	cdrdao-[0-9]*:../../sysutils/cdrdao
DEPENDS+=	{cdrtools,cdrtools-ossdvd}-[0-9]*:../../sysutils/cdrtools

USE_TOOLS+=	msgmerge pkg-config perl

CMAKE_CONFIGURE_ARGS+=	-DK3B_BUILD_MUSE_DECODER_PLUGIN=OFF
CMAKE_CONFIGURE_ARGS+=	-DKAUTH_DBUS_DIR=${PREFIX}/share/examples/k3b

INSTALLATION_DIRS+=	share/examples/k3b

ONLY_FOR_PLATFORM=	FreeBSD-*-* Linux-*-* NetBSD-*-* DragonFly-*-*

SUBST_CLASSES+=		pathfix
SUBST_STAGE.pathfix=	pre-configure
SUBST_MESSAGE.pathfix=	Add cdrtools path.
SUBST_FILES.pathfix=	libk3b/core/k3bexternalbinmanager.cpp
SUBST_SED.pathfix=	-e 's:"/usr/bin/":"${LOCALBASE}/bin", "/usr/bin/":g'

SUBST_CLASSES+=		fix-moc
SUBST_STAGE.fix-moc=	post-configure
SUBST_MESSAGE.fix-moc=	Cleaning up MOC includes
SUBST_FILES.fix-moc=	_KDE_build/plugins/*/*/CMakeFiles/*_autogen.dir/AutogenInfo.json
SUBST_NOOP_OK.fix-moc=	yes
SUBST_SED.fix-moc=	-e 's;"${PREFIX}/include",;;g'

MAKE_DIRS+=		${PKG_SYSCONFDIR}/xdg
CONF_FILES+=		${PREFIX}/share/examples/k3b/org.kde.k3b.conf \
			${PKG_SYSCONFBASE}/dbus-1/system.d/org.kde.k3b.conf

.include "../../mk/dlopen.buildlink3.mk"
BUILDLINK_TRANSFORM+=	opt:-ldl:${BUILDLINK_LDADD.dl:M*}

.include "../../audio/flac/buildlink3.mk"
.include "../../audio/lame/buildlink3.mk"
.include "../../audio/libmad/buildlink3.mk"
.include "../../audio/libsamplerate/buildlink3.mk"
.include "../../audio/libsndfile/buildlink3.mk"
#.include "../../audio/musepack/buildlink3.mk"
.include "../../audio/taglib/buildlink3.mk"
.include "../../devel/kf6-kcmutils/buildlink3.mk"
.include "../../devel/kf6-knotifyconfig/buildlink3.mk"
.include "../../net/kf6-knewstuff/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../multimedia/ffmpeg7/buildlink3.mk"
.include "../../multimedia/libdvdread/buildlink3.mk"
.include "../../multimedia/libkcddb/buildlink3.mk"
.include "../../sysutils/kf6-kfilemetadata/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../www/qt6-qtwebengine/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
