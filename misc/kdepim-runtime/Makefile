# $NetBSD: Makefile,v 1.29 2026/02/06 10:05:19 wiz Exp $

DISTNAME=	kdepim-runtime-${KAPPSVER}
PKGREVISION=	3
CATEGORIES=	misc

HOMEPAGE=	https://community.kde.org/KDE_PIM
COMMENT=	Extends the functionality of kdepim
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2.1

# resources/ews/test/isolatedtestbase.cpp:15:10: fatal error: ewsresourceinterface.h: No such file or directory
CMAKE_GENERATORS_INCOMPATIBLE=	ninja

.include "../../meta-pkgs/kde/applications.mk"

TOOL_DEPENDS+=	kf6-kdoctools>=6.18.0:../../devel/kf6-kdoctools

USE_TOOLS+=	msgmerge pkg-config

.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/kf6-knotifyconfig/buildlink3.mk"
.include "../../devel/libkgapi/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mail/kmbox/buildlink3.mk"
.include "../../misc/kf6-kdav/buildlink3.mk"
.include "../../misc/pimcommon/buildlink3.mk"
.include "../../security/qca2-qt6/buildlink3.mk"
.include "../../security/qt6-qtkeychain/buildlink3.mk"
.include "../../security/qt6-qtnetworkauth/buildlink3.mk"
.include "../../textproc/libkolabxml/buildlink3.mk"
.include "../../time/akonadi-calendar/buildlink3.mk"
.include "../../time/kf6-kholidays/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
