# $NetBSD: Makefile,v 1.2 2026/01/07 08:48:56 wiz Exp $

DISTNAME=	libksysguard-${PLASMAVER}
PKGREVISION=	1
CATEGORIES=	sysutils

HOMEPAGE=	https://userbase.kde.org/KSysGuard
COMMENT=	Library to track and control the processes running in your system
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2.1

.include "../../meta-pkgs/kde/plasma6.mk"

TOOL_DEPENDS+=	kf6-kdoctools>=6.18.0:../../devel/kf6-kdoctools

USE_TOOLS+=	msgmerge pkg-config

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "NetBSD" && exists(/usr/include/sys/pset.h)
RT_LIB_SCHED=	rt
.else
RT_LIB_SCHED=	# empty
.endif
CMAKE_CONFIGURE_ARGS+=	-DRT_LIB_SCHED=${RT_LIB_SCHED}

CMAKE_CONFIGURE_ARGS.NetBSD+=	-DKVM_LIB=kvm

CMAKE_CONFIGURE_ARGS+=	-DKAUTH_DBUS_DIR=${PREFIX}/share/examples/libksysguard

MAKE_DIRS+=	${PKG_SYSCONFDIR}/dbus-1/system.d
CONF_FILES+=	${PREFIX}/share/examples/libksysguard/org.kde.ksysguard.processlisthelper.conf \
		${PKG_SYSCONFDIR}/dbus-1/system.d/org.kde.ksysguard.processlisthelper.conf

INSTALLATION_DIRS+=	share/examples/libksysguard

.include "../../devel/kf6-ki18n/buildlink3.mk"
.include "../../devel/kf6-kservice/buildlink3.mk"
.include "../../net/kf6-knewstuff/buildlink3.mk"
.include "../../security/kf6-kauth/buildlink3.mk"
.include "../../sysutils/kf6-solid/buildlink3.mk"
.include "../../x11/libXres/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
