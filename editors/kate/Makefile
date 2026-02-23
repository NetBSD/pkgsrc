# $NetBSD: Makefile,v 1.106 2026/02/23 09:18:39 wiz Exp $

DISTNAME=	kate-${KAPPSVER}
PKGREVISION=	3
CATEGORIES=	editors

HOMEPAGE=	https://apps.kde.org/kate/
COMMENT=	KDE Advanced Text Editor
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2 AND gnu-fdl-v1.2

.include "../../meta-pkgs/kde/applications.mk"

TOOL_DEPENDS+=	kf6-kdoctools>=6.18.0:../../devel/kf6-kdoctools

USE_TOOLS+=	msgmerge

USE_CXX_FEATURES+=	charconv

LDFLAGS.SunOS+=	-lsocket

# PCH-enabled builds cause failures with RELRO enabled, e.g., on NetBSD 9.x.
CMAKE_CONFIGURE_ARGS+=	-DBUILD_PCH=OFF

# generation of kded.moc fails when ${PREFIX}/include in the moc include path
SUBST_CLASSES+=		fix-moc
SUBST_STAGE.fix-moc=	post-configure
SUBST_MESSAGE.fix-moc=	Cleaning up MOC includes
SUBST_FILES.fix-moc=	_KDE_build/addons/*/CMakeFiles/*_autogen.dir/AutogenInfo.json
SUBST_FILES.fix-moc+=	_KDE_build/addons/*/*/CMakeFiles/*_autogen.dir/AutogenInfo.json
SUBST_NOOP_OK.fix-moc=	yes
SUBST_SED.fix-moc=	-e 's;"${PREFIX}/include",;;g'

# .desktop files should not be executable.
post-install:
	${CHMOD} a-x ${DESTDIR}${PREFIX}/share/applications/org.kde.kate.desktop

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../devel/kf6-kitemmodels/buildlink3.mk"
.include "../../devel/kf6-ktexteditor/buildlink3.mk"
.include "../../devel/kf6-threadweaver/buildlink3.mk"
.include "../../misc/kf6-kuserfeedback/buildlink3.mk"
.include "../../net/kf6-knewstuff/buildlink3.mk"
.include "../../security/qt6-qtkeychain/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
