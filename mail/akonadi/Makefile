# $NetBSD: Makefile,v 1.127 2024/05/29 16:33:18 adam Exp $

DISTNAME=	akonadi-${KAPPSVER}
PKGREVISION=	2
CATEGORIES=	mail

HOMEPAGE=	https://community.kde.org/KDE_PIM/Akonadi
COMMENT=	PIM layer, which provides an asynchronous API to access all kind of PIM data
LICENSE=	gnu-lgpl-v2

.include "../../meta-pkgs/kde/applications.mk"

TOOL_DEPENDS+=	libxslt-[0-9]*:../../textproc/libxslt
DEPENDS+=	kdesignerplugin-[0-9]*:../../x11/kdesignerplugin

CMAKE_ARGS+=	-DMYSQLD_EXECUTABLE="${PREFIX}/sbin/mysqld"
CMAKE_ARGS+=	-DPOSTGRES_PATH="${PREFIX}/bin"
CMAKE_ARGS+=	-DINSTALL_APPARMOR=FALSE

USE_TOOLS+=	gmake msgmerge pkg-config

LDFLAGS.SunOS+=	-lsocket -lnsl

.include "options.mk"

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
.include "../../devel/kio/buildlink3.mk"
.include "../../devel/kitemmodels/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/atomic64.mk"
.include "../../mk/bsd.pkg.mk"
