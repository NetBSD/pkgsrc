# $NetBSD: Makefile,v 1.30 2024/05/29 16:34:24 adam Exp $

DISTNAME=	dolphin-${KAPPSVER}
PKGREVISION=	3
CATEGORIES=	sysutils

HOMEPAGE=	https://kde.org/applications/system/dolphin/
COMMENT=	KDE File Manager
LICENSE=	gnu-gpl-v2 AND gnu-fdl-v1.2

.include "../../meta-pkgs/kde/applications.mk"

TOOL_DEPENDS+=	kdoctools>=5.19.0:../../devel/kdoctools
DEPENDS+=	kio-extras>=${KAPPSVER}:../../devel/kio-extras
DEPENDS+=	kinit>=5.70.0nb6:../../x11/kinit

REPLACE_RUBY+=	src/settings/services/servicemenuinstallation
REPLACE_RUBY+=	src/settings/services/servicemenudeinstallation

.include "../../lang/ruby/replace.mk"

USE_TOOLS+=	msgmerge

MAKE_ENV+=	LD_LIBRARY_PATH=${WRKSRC}/_KDE_build/bin

.include "../../devel/kcmutils/buildlink3.mk"
.include "../../devel/kparts/buildlink3.mk"
.include "../../lang/ruby/buildlink3.mk"
.include "../../misc/kuserfeedback/buildlink3.mk"
.include "../../net/knewstuff/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../sysutils/baloo-widgets/buildlink3.mk"
.include "../../x11/kactivities5/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
