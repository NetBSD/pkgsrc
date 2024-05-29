# $NetBSD: Makefile,v 1.92 2024/05/29 16:32:23 adam Exp $

DISTNAME=	kate-${KAPPSVER}
PKGREVISION=	3
CATEGORIES=	editors

HOMEPAGE=	https://www.kde.org/applications/utilities/kate/
COMMENT=	KDE Advanced Text Editor
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2 AND gnu-fdl-v1.2

.include "../../meta-pkgs/kde/applications.mk"

TOOL_DEPENDS+=	kdoctools>=5.19.0:../../devel/kdoctools

USE_TOOLS+=	msgmerge

USE_CXX_FEATURES+=	charconv

LDFLAGS.SunOS+=	-lsocket

# PCH-enabled builds cause failures with RELRO enabled, e.g., on NetBSD 9.x.
CMAKE_ARGS+=	-DBUILD_PCH=OFF

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
.include "../../devel/kitemmodels/buildlink3.mk"
.include "../../devel/ktexteditor/buildlink3.mk"
.include "../../devel/threadweaver/buildlink3.mk"
.include "../../misc/kuserfeedback/buildlink3.mk"
.include "../../net/knewstuff/buildlink3.mk"
.include "../../x11/kactivities5/buildlink3.mk"
.include "../../x11/plasma-framework/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
