# $NetBSD: Makefile,v 1.36 2022/06/22 15:45:59 wiz Exp $

DISTNAME=	ownCloud-2.7.6.3261
PKGNAME=	${DISTNAME:S/ownCloud/owncloudclient/1}
PKGREVISION=	3
CATEGORIES=	net
MASTER_SITES=	https://download.owncloud.com/desktop/ownCloud/stable/${PKGVERSION_NOREV}/source/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://owncloud.com/
COMMENT=	Synchronization program for ownCloud
LICENSE=	gnu-gpl-v2

BROKEN=		"Needs to be updated, for qt5 compatibility"

USE_CMAKE=	yes
USE_LANGUAGES=	c c++

TOOL_DEPENDS+=	extra-cmake-modules-[0-9]*:../../devel/extra-cmake-modules

CMAKE_ARGS+=	-DSYSCONF_INSTALL_DIR=${PKG_SYSCONFDIR}
CMAKE_ARGS+=	-DBUILD_SHELL_INTEGRATION=OFF
CMAKE_ARGS+=	-DBUILD_TESTING=OFF

EGDIR=		${PREFIX}/share/examples/owncloudclient
CONF_FILES=	${EGDIR}/sync-exclude.lst \
		${PKG_SYSCONFDIR}/ownCloud/sync-exclude.lst

OWN_DIRS+=	${PKG_SYSCONFDIR}/ownCloud

.include "../../mk/bsd.prefs.mk"
BUILDLINK_API_DEPENDS.sqlite3+=	sqlite3>=3.9.0
.include "../../databases/sqlite3/buildlink3.mk"
.if ${OPSYS} != "Linux"
.  include "../../devel/libinotify/buildlink3.mk"
.endif
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../security/qt5-qtkeychain/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
