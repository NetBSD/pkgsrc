# $NetBSD: Makefile,v 1.10 2024/05/16 06:15:11 wiz Exp $

DISTNAME=	kdepim-runtime-${KAPPSVER}
PKGREVISION=	2
CATEGORIES=	misc

HOMEPAGE=	https://community.kde.org/KDE_PIM
COMMENT=	Extends the functionality of kdepim
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2.1

.include "../../meta-pkgs/kde/applications.mk"

TOOL_DEPENDS+=	kdoctools>=5.19.0:../../devel/kdoctools

USE_TOOLS+=	msgmerge pkg-config

.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/knotifyconfig/buildlink3.mk"
.include "../../devel/libkgapi/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mail/kmbox/buildlink3.mk"
.include "../../misc/akonadi-notes/buildlink3.mk"
.include "../../misc/kdav/buildlink3.mk"
.include "../../misc/pimcommon/buildlink3.mk"
.include "../../security/qca2-qt5/buildlink3.mk"
.include "../../security/qt5-qtkeychain/buildlink3.mk"
.include "../../textproc/libkolabxml/buildlink3.mk"
.include "../../time/akonadi-calendar/buildlink3.mk"
.include "../../time/kholidays/buildlink3.mk"
.include "../../x11/qt5-qtnetworkauth/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
