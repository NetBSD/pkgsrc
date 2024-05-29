# $NetBSD: Makefile,v 1.76 2024/05/29 16:33:55 adam Exp $

DISTNAME=	kget-${KAPPSVER}
PKGREVISION=	2
CATEGORIES=	net

HOMEPAGE=	https://kde.org/applications/internet/kget/
COMMENT=	download manager for KDE
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2 AND gnu-fdl-v1.2

.include "../../meta-pkgs/kde/applications.mk"

TOOL_DEPENDS+=	kdoctools>=5.19.0:../../devel/kdoctools

USE_TOOLS+=	pkg-config msgmerge

# disable until plasma-workspace is available
CMAKE_ARGS+=	-DCMAKE_DISABLE_FIND_PACKAGE_LibKWorkspace=TRUE

REPLACE_PERL+=	conf/kget_sensitive.pl conf/kget_limitdownloads.pl

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/kcmutils/buildlink3.mk"
.include "../../devel/knotifyconfig/buildlink3.mk"
.include "../../devel/kparts/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../net/libktorrent/buildlink3.mk"
.include "../../net/libmms/buildlink3.mk"
.include "../../security/qgpgme/buildlink3.mk"
.include "../../security/qca2-qt5/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
