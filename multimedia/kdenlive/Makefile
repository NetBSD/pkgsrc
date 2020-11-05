# $NetBSD: Makefile,v 1.64 2020/11/05 09:08:47 ryoon Exp $

DISTNAME=	kdenlive-${KAPPSVER}
PKGREVISION=	3
CATEGORIES=	multimedia

HOMEPAGE=	https://www.kdenlive.org/
COMMENT=	KDE video editor
LICENSE=	gnu-gpl-v2

.include "../../meta-pkgs/kde/applications.mk"

BUILD_DEPENDS+=	kdoctools>=5.19.0:../../devel/kdoctools
DEPENDS+=	dvdauthor>=0.6.18:../../multimedia/dvdauthor
DEPENDS+=	ffplay4-[0-9]*:../../multimedia/ffplay4

USE_TOOLS+=	msgmerge

CXXFLAGS.NetBSD+=	-DHAVE_LOCALE_H
CMAKE_ARGS+=		-DCMAKE_DISABLE_FIND_PACKAGE_LibV4L2=TRUE
CMAKE_ARGS+=		-DFFMPEG_SUFFIX=4

SUBST_CLASSES+=		xdg
SUBST_STAGE.xdg=	pre-configure
SUBST_MESSAGE.xdg=	Install via examples dir.
SUBST_FILES.xdg=	data/CMakeLists.txt
SUBST_SED.xdg=		-e 's:{CONFIG_INSTALL_DIR}:{KDE_INSTALL_XDG_EX_DIR}:'

MAKE_DIRS+=	${PKG_SYSCONFDIR}/xdg
CONF_FILES+=	${PREFIX}/share/examples/kde-xdg/kdenlive_keyboardschemes.knsrc \
		${PKG_SYSCONFDIR}/xdg/kdenlive_keyboardschemes.knsrc
CONF_FILES+=	${PREFIX}/share/examples/kde-xdg/kdenlive_renderprofiles.knsrc \
		${PKG_SYSCONFDIR}/xdg/kdenlive_renderprofiles.knsrc
CONF_FILES+=	${PREFIX}/share/examples/kde-xdg/kdenlive_titles.knsrc \
		${PKG_SYSCONFDIR}/xdg/kdenlive_titles.knsrc
CONF_FILES+=	${PREFIX}/share/examples/kde-xdg/kdenlive_wipes.knsrc \
		${PKG_SYSCONFDIR}/xdg/kdenlive_wipes.knsrc

.include "../../devel/kdeclarative/buildlink3.mk"
.include "../../devel/knotifyconfig/buildlink3.mk"
.include "../../devel/rttr/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../multimedia/ffmpeg4/buildlink3.mk"
.include "../../multimedia/frei0r/buildlink3.mk"
.include "../../multimedia/mlt/buildlink3.mk"
.include "../../net/knewstuff/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../sysutils/kfilemetadata5/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtquickcontrols2/buildlink3.mk"
.include "../../x11/qt5-qtwebkit/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
