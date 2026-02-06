# $NetBSD: Makefile,v 1.141 2026/02/06 10:05:10 wiz Exp $

DISTNAME=	akonadi-${KAPPSVER}
PKGREVISION=	3
CATEGORIES=	mail

HOMEPAGE=	https://community.kde.org/KDE_PIM/Akonadi
COMMENT=	PIM layer, which provides an asynchronous API to access all kind of PIM data
LICENSE=	gnu-lgpl-v2

.include "../../meta-pkgs/kde/applications.mk"

TOOL_DEPENDS+=	libxslt-[0-9]*:../../textproc/libxslt
#DEPENDS+=	kf6-kdesignerplugin-[0-9]*:../../x11/kf6-kdesignerplugin

CMAKE_CONFIGURE_ARGS+=	-DMYSQLD_EXECUTABLE="${PREFIX}/sbin/mysqld"
CMAKE_CONFIGURE_ARGS+=	-DPOSTGRES_PATH="${PREFIX}/bin"
CMAKE_CONFIGURE_ARGS+=	-DINSTALL_APPARMOR=FALSE
CMAKE_CONFIGURE_ARGS+=	-DBUILD_TESTING=OFF

USE_TOOLS+=	gmake msgmerge pkg-config

LDFLAGS.SunOS+=	-lsocket -lnsl

.include "options.mk"

# generation of kded.moc fails when ${PREFIX}/include in the moc include path
SUBST_CLASSES+=		fix-moc
SUBST_STAGE.fix-moc=	post-configure
SUBST_MESSAGE.fix-moc=	Cleaning up MOC includes
SUBST_FILES.fix-moc=	_KDE_build/src/agentbase/CMakeFiles/KPim6AkonadiAgentWidgetBase_autogen.dir/AutogenInfo.json
SUBST_NOOP_OK.fix-moc=	yes
SUBST_SED.fix-moc=	-e 's;"${PREFIX}/qt6/include/QtWidgets",;;g'

SUBST_CLASSES+=		xdg
SUBST_STAGE.xdg=	pre-configure
SUBST_MESSAGE.xdg=	Install via examples dir.
SUBST_FILES.xdg=	src/server/CMakeLists.txt
SUBST_SED.xdg=		-e 's:{KDE_INSTALL_CONFDIR}:{KDE_INSTALL_XDG_EX_DIR}:'

MAKE_DIRS+=	${PKG_SYSCONFDIR}/xdg/akonadi
CONF_FILES+=	${PREFIX}/share/examples/kde-xdg/akonadi/mysql-global.conf \
		${PKG_SYSCONFDIR}/xdg/akonadi/mysql-global.conf
CONF_FILES+=	${PREFIX}/share/examples/kde-xdg/akonadi/mysql-global-mobile.conf \
		${PKG_SYSCONFDIR}/xdg/akonadi/mysql-global-mobile.conf

.include "../../databases/shared-mime-info/buildlink3.mk"
.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/kf6-kio/buildlink3.mk"
.include "../../devel/kf6-kitemmodels/buildlink3.mk"
.include "../../devel/qt6-qttools/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/kf6-kxmlgui/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/atomic64.mk"
.include "../../mk/bsd.pkg.mk"
