# $NetBSD: Makefile,v 1.72 2024/02/06 11:17:39 markd Exp $

DISTNAME=	juk-${KAPPSVER}
CATEGORIES=	multimedia

HOMEPAGE=	https://kde.org/applications/multimedia/juk/
COMMENT=	Jukebox, tagger and music collection manager
LICENSE=	gnu-gpl-v2 AND gnu-fdl-v1.2 AND gnu-lgpl-v2

.include "../../meta-pkgs/kde/applications.mk"

TOOL_DEPENDS+=	kdoctools>=5.19.0:../../devel/kdoctools

USE_TOOLS+=	msgmerge

.include "../../audio/taglib/buildlink3.mk"
.include "../../devel/kio/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
