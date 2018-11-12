# $NetBSD: Makefile,v 1.26 2018/11/12 03:51:25 ryoon Exp $

DISTNAME=	kcodecs-${KF5VER}
PKGREVISION=	3
CATEGORIES=	textproc

HOMEPAGE=	https://community.kde.org/Frameworks
COMMENT=	Collection of methods to manipulate strings using various encodings
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2.1

.include "../../meta-pkgs/kde/kf5.mk"

BUILD_DEPENDS+=	gperf-[0-9]*:../../devel/gperf

SUBST_CLASSES+=		xdg
SUBST_STAGE.xdg=	pre-configure
SUBST_FILES.xdg=	CMakeLists.txt
SUBST_SED.xdg=		-e 's:{KDE_INSTALL_CONFDIR}:{KDE_INSTALL_XDG_EX_DIR}:'

MAKE_DIRS+=		${PKG_SYSCONFDIR}/xdg
CONF_FILES+=		${PREFIX}/share/examples/kde-xdg/kcodecs.categories \
			${PKG_SYSCONFDIR}/xdg/kcodecs.categories

.include "../../x11/qt5-qtbase/buildlink3.mk"
BUILDLINK_DEPMETHOD.qt5-qttools= build
.include "../../x11/qt5-qttools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
