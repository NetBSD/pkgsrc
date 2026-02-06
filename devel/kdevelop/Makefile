# $NetBSD: Makefile,v 1.102 2026/02/06 10:04:29 wiz Exp $

DISTNAME=	kdevelop-${KAPPSVER}
PKGREVISION=	4
CATEGORIES=	devel

HOMEPAGE=	https://www.kdevelop.org/
COMMENT=	Integrated Development Environment for Unix/X11/KDE
LICENSE=	gnu-lgpl-v2.1 AND gnu-gpl-v2 AND gnu-fdl-v1.2

.include "../../meta-pkgs/kde/applications.mk"

TOOL_DEPENDS+=	kf6-kdoctools>=6.18.0:../../devel/kf6-kdoctools

USE_TOOLS+=	gmake gtar pkg-config #perl msgfmt

REPLACE_BASH+=	kdevplatform/util/kdevplatform_shell_environment.sh

CHECK_INTERPRETER_SKIP=	share/kdevplatform/shellutils/.zshrc

CMAKE_CONFIGURE_ARGS+=	-DBUILD_TESTING=OFF
# dont build cmake plugin as odd static_assert fail
CMAKE_CONFIGURE_ARGS+=	-DBUILD_cmake=OFF -DBUILD_cmakebuilder=OFF

# not set in boost and gcc complains
CFLAGS+=	-D__NVCC___WORKAROUND_GUARD=0 -D__NVCC__=0

pre-configure:
	ln -s ${TOOLS_DIR}/bin/gtar ${TOOLS_DIR}/bin/tar

.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/kf6-kcmutils/buildlink3.mk"
.include "../../devel/kf6-kitemmodels/buildlink3.mk"
.include "../../devel/kf6-knotifyconfig/buildlink3.mk"
.include "../../devel/kf6-krunner/buildlink3.mk"
.include "../../devel/kf6-ktexteditor/buildlink3.mk"
.include "../../devel/kf6-purpose/buildlink3.mk"
.include "../../devel/kf6-threadweaver/buildlink3.mk"
.include "../../devel/libkomparediff2/buildlink3.mk"
.include "../../devel/qt6-qt5compat/buildlink3.mk"
.include "../../devel/subversion-base/buildlink3.mk"
.include "../../lang/clang/buildlink3.mk"
.include "../../net/kf6-knewstuff/buildlink3.mk"
.include "../../sysutils/plasma6-libksysguard/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../textproc/kf6-ktexttemplate/buildlink3.mk"
.include "../../www/qt6-qtwebengine/buildlink3.mk"
.include "../../x11/kf6-kxmlgui/buildlink3.mk"
.include "../../x11/plasma6-libplasma/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
