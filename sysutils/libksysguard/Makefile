# $NetBSD: Makefile,v 1.9 2024/05/29 16:34:28 adam Exp $

DISTNAME=	libksysguard-${PLASMAVER}
PKGREVISION=	2
CATEGORIES=	sysutils

HOMEPAGE=	https://userbase.kde.org/KSysGuard
COMMENT=	Library to track and control the processes running in your system
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2.1

.include "../../meta-pkgs/kde/plasma5.mk"

TOOL_DEPENDS+=	kdoctools>=5.19.0:../../devel/kdoctools

USE_TOOLS+=	msgmerge pkg-config

USE_CXX_FEATURES+=	c++20

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "NetBSD" && exists(/usr/include/sys/pset.h)
RT_LIB_SCHED=	rt
.else
RT_LIB_SCHED=	# empty
.endif
CMAKE_ARGS+=	-DRT_LIB_SCHED=${RT_LIB_SCHED}
CMAKE_ARGS.NetBSD+=	-DKVM_LIB=kvm

CMAKE_ARGS+=	-DKAUTH_DBUS_DIR=${PREFIX}/share/examples/libksysguard

MAKE_DIRS+=	${PKG_SYSCONFDIR}/dbus-1/system.d
CONF_FILES+=	${PREFIX}/share/examples/libksysguard/org.kde.ksysguard.processlisthelper.conf \
		${PKG_SYSCONFDIR}/dbus-1/system.d/org.kde.ksysguard.processlisthelper.conf

INSTALLATION_DIRS+=	share/examples/libksysguard

.include "../../net/knewstuff/buildlink3.mk"
.include "../../x11/plasma-framework/buildlink3.mk"
.include "../../x11/libXres/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
CMAKE_ARGS+=	-DCMAKE_DISABLE_FIND_PACKAGE_Qt5WebEngineWidgets:BOOL=TRUE
#.include "../../x11/qt5-qtwebengine/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
