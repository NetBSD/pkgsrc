# $NetBSD: Makefile,v 1.28 2023/11/12 13:23:29 wiz Exp $

PKGNAME=	${DISTNAME:S/-/-tray-monitor-qt5-/}
PKGREVISION=	8
COMMENT=	System tray monitor for Bacula - The Network Backup Solution

DISTINFO_FILE=		${.CURDIR}/../../sysutils/bacula/distinfo
PATCHDIR=		${.CURDIR}/../../sysutils/bacula/patches

USE_TOOLS+=		gmake pkg-config
CONFIGURE_ARGS+=	--enable-client-only
CONFIGURE_ARGS+=	--enable-bat

# Uses typeof, cannot use standard C++11
FORCE_CXX_STD=		gnu++11

BUILD_DIRS=		src/qt-console/tray-monitor

INSTALLATION_DIRS=	bin share/examples/bacula

CONF_FILES+=		${EXAMPLESDIR}/tray-monitor.conf ${PKG_SYSCONFDIR}/tray-monitor.conf

pre-configure:
	${LN} -sf ${QTDIR}/bin/qmake ${BUILDLINK_DIR}/bin/

post-install:
	${INSTALL_DATA} ${WRKSRC}/src/qt-console/tray-monitor/tray-monitor.conf ${DESTDIR}${EXAMPLESDIR}

.include "../../sysutils/bacula/Makefile.common"
.include "../../sysutils/bacula/buildlink3.mk"
.include "../../devel/libinotify/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
