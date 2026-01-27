# $NetBSD: Makefile,v 1.82 2026/01/27 08:40:13 wiz Exp $

DISTNAME=	parley-${KAPPSVER}
PKGREVISION=	2
CATEGORIES=	misc

HOMEPAGE=	https://kde.org/applications/education/parley/
COMMENT=	KDE vocabulary trainer
LICENSE=	gnu-gpl-v2 AND gnu-fdl-v1.2

.include "../../meta-pkgs/kde/applications.mk"

TOOL_DEPENDS+=	kf6-kdoctools>=6.18.0:../../devel/kf6-kdoctools
DEPENDS+=	translate-shell-[0-9]*:../../textproc/translate-shell

USE_TOOLS+=	msgmerge pkg-config

.include "../../devel/kf6-kcmutils/buildlink3.mk"
.include "../../misc/libkeduvocdocument/buildlink3.mk"
.include "../../net/kf6-knewstuff/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../www/qt6-qtwebengine/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
