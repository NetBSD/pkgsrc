# $NetBSD: Makefile,v 1.78 2024/02/06 11:17:37 markd Exp $

DISTNAME=	kwordquiz-${KAPPSVER}
CATEGORIES=	misc

HOMEPAGE=	https://kde.org/applications/education/kwordquiz/
COMMENT=	KDE flash card trainer
LICENSE=	gnu-gpl-v2 AND gnu-fdl-v1.2

.include "../../meta-pkgs/kde/applications.mk"

TOOL_DEPENDS+=	kdoctools>=5.19.0:../../devel/kdoctools

USE_TOOLS+=	msgmerge

.include "../../devel/knotifyconfig/buildlink3.mk"
.include "../../misc/libkeduvocdocument/buildlink3.mk"
.include "../../net/knewstuff/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/kirigami-addons/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtquickcontrols2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
