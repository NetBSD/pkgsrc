# $NetBSD: Makefile,v 1.68 2024/02/06 11:17:38 markd Exp $

DISTNAME=	parley-${KAPPSVER}
CATEGORIES=	misc

HOMEPAGE=	https://kde.org/applications/education/parley/
COMMENT=	KDE vocabulary trainer
LICENSE=	gnu-gpl-v2 AND gnu-fdl-v1.2

.include "../../meta-pkgs/kde/applications.mk"

TOOL_DEPENDS+=	kdoctools>=${KF5VER}:../../devel/kdoctools
DEPENDS+=	translate-shell-[0-9]*:../../textproc/translate-shell

USE_TOOLS+=	msgmerge pkg-config

.include "../../devel/kcmutils/buildlink3.mk"
.include "../../misc/libkeduvocdocument/buildlink3.mk"
.include "../../net/knewstuff/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtwebengine/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
