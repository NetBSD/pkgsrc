# $NetBSD: Makefile,v 1.70 2024/02/06 11:05:21 markd Exp $

DISTNAME=	ksirk-${KAPPSVER}
CATEGORIES=	games

HOMEPAGE=	https://kde.org/applications/games/ksirk/
COMMENT=	Computerized version of a well known strategy game
LICENSE=	gnu-lgpl-v2 AND gnu-gpl-v2 AND gnu-fdl-v1.2

.include "../../meta-pkgs/kde/applications.mk"

TOOL_DEPENDS+=	kdoctools>=5.19.0:../../devel/kdoctools

USE_TOOLS+=	msgmerge

LDFLAGS.SunOS+=	-lsocket -lnsl -lresolv

.include "../../games/libkdegames/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../multimedia/phonon-qt5/buildlink3.mk"
.include "../../security/qca2-qt5/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
