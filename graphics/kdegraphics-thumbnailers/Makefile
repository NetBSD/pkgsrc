# $NetBSD: Makefile,v 1.93 2026/05/14 16:41:12 ryoon Exp $

DISTNAME=	kdegraphics-thumbnailers-${KAPPSVER}
PKGREVISION=	4
CATEGORIES=	graphics

HOMEPAGE=	https://kde.org/applications/graphics/
COMMENT=	Graphics file format thumbnailers for KDE
LICENSE=	gnu-gpl-v2 AND gnu-fdl-v1.2 AND gnu-lgpl-v2

.include "../../meta-pkgs/kde/applications.mk"

.include "../../archivers/kf6-karchive/buildlink3.mk"
.include "../../devel/kf6-kio/buildlink3.mk"
.include "../../graphics/kdegraphics-mobipocket/buildlink3.mk"
.include "../../graphics/libkdcraw/buildlink3.mk"
.include "../../graphics/libkexiv2/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
