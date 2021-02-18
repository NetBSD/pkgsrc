# $NetBSD: Makefile,v 1.2 2021/02/18 00:15:46 gutteridge Exp $

DISTNAME=	dolphin-${KAPPSVER}
PKGREVISION=	1
CATEGORIES=	sysutils

HOMEPAGE=	https://kde.org/applications/system/dolphin/
COMMENT=	KDE File Manager
LICENSE=	gnu-gpl-v2 AND gnu-fdl-v1.2

.include "../../meta-pkgs/kde/applications.mk"

BUILD_DEPENDS+=	kdoctools>=5.19.0:../../devel/kdoctools
DEPENDS+=	kio-extras>=${KAPPSVER}:../../devel/kio-extras
DEPENDS+=	kinit>=5.70.0nb6:../../x11/kinit

REPLACE_RUBY+=	src/settings/services/servicemenuinstallation
REPLACE_RUBY+=	src/settings/services/servicemenudeinstallation

.include "../../lang/ruby/replace.mk"

USE_TOOLS+=	msgmerge

SUBST_CLASSES+=		xdg
SUBST_STAGE.xdg=	pre-configure
SUBST_MESSAGE.xdg=	Install via examples dir.
SUBST_FILES.xdg=	src/CMakeLists.txt
SUBST_SED.xdg=		-e 's:{KDE_INSTALL_CONFDIR}:{KDE_INSTALL_XDG_EX_DIR}:'

MAKE_DIRS+=	${PKG_SYSCONFDIR}/xdg
CONF_FILES+=	${PREFIX}/share/examples/kde-xdg/servicemenu.knsrc \
		${PKG_SYSCONFDIR}/xdg/servicemenu.knsrc

MAKE_ENV+=	LD_LIBRARY_PATH=${WRKSRC}/_KDE_build/bin

.include "../../devel/kcmutils/buildlink3.mk"
.include "../../devel/kparts/buildlink3.mk"
.include "../../lang/ruby/buildlink3.mk"
.include "../../net/knewstuff/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../sysutils/baloo-widgets/buildlink3.mk"
.include "../../x11/kactivities5/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
