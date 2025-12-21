# $NetBSD: Makefile,v 1.53 2025/12/21 14:10:07 markd Exp $

DISTNAME=	khelpcenter-${KAPPSVER}
CATEGORIES=	misc

HOMEPAGE=	https://userbase.kde.org/KHelpCenter
COMMENT=	Application to show KDE Applications' documentation
LICENSE=	gnu-gpl-v2

.include "../../meta-pkgs/kde/applications.mk"

TOOL_DEPENDS+=	kf6-kdoctools>=6.18.0:../../devel/kf6-kdoctools

USE_TOOLS+=	msgmerge pkg-config

REPLACE_PYTHON+=	searchhandlers/khc_mansearch.py

.include "../../devel/kf6-kdoctools/buildlink3.mk"
.include "../../devel/kf6-kio/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../textproc/kf6-ktexttemplate/buildlink3.mk"
.include "../../textproc/xapian/buildlink3.mk"
.include "../../wip/qt6-qtwebengine/buildlink3.mk"
.include "../../x11/kf6-kxmlgui/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
