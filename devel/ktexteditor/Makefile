# $NetBSD: Makefile,v 1.33 2019/08/11 13:18:45 wiz Exp $

DISTNAME=	ktexteditor-${KF5VER}
PKGREVISION=	1
CATEGORIES=	devel

HOMEPAGE=	https://community.kde.org/Frameworks
COMMENT=	Advanced embeddable text editor
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2.1

.include "../../meta-pkgs/kde/kf5.mk"

USE_TOOLS+=	msgmerge pkg-config perl

CMAKE_ARGS+=	-DKAUTH_DBUS_DIR=${PREFIX}/share/examples/ktexteditor

CONF_FILES+=	${PREFIX}/share/examples/ktexteditor/org.kde.ktexteditor.katetextbuffer.conf \
		${PKG_SYSCONFDIR}/dbus-1/system.d/org.kde.ktexteditor.katetextbuffer.conf

MAKE_DIRS+=		${PKG_SYSCONFDIR}/dbus-1/system.d
INSTALLATION_DIRS+=	share/examples/ktexteditor

SUBST_CLASSES+=		xdg
SUBST_STAGE.xdg=	pre-configure
SUBST_MESSAGE.xdg=	Install via examples dir.
SUBST_FILES.xdg=	CMakeLists.txt
SUBST_SED.xdg=		-e 's:{KDE_INSTALL_CONFDIR}:{KDE_INSTALL_XDG_EX_DIR}:'

MAKE_DIRS+=	${PKG_SYSCONFDIR}/xdg
CONF_FILES+=	${PREFIX}/share/examples/kde-xdg/ktexteditor.categories \
		${PKG_SYSCONFDIR}/xdg/ktexteditor.categories

.include "../../devel/libgit2/buildlink3.mk"
.include "../../devel/kparts/buildlink3.mk"
.include "../../textproc/syntax-highlighting/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
