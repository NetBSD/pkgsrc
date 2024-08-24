# $NetBSD: Makefile,v 1.74 2024/08/24 06:16:06 markd Exp $

DISTNAME=	dikt-2v
CATEGORIES=	textproc x11
MASTER_SITES=	${MASTER_SITE_GITLAB:=-/project/46530021/uploads/755d2ad7b4979d3206a3a5a49de78141/}
EXTRACT_SUFX=	.txz

MAINTAINER=	cheusov@NetBSD.org
HOMEPAGE=	https://www.dikt.tv/
COMMENT=	Dictionary protocol client for KDE
LICENSE=	2-clause-bsd

USE_TOOLS+=	msgmerge

.include "../../meta-pkgs/kde/applications.mk"

.include "../../devel/kconfig/buildlink3.mk"
.include "../../devel/kio/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/kiconthemes/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../sysutils/kdbusaddons/buildlink3.mk"
.include "../../x11/kguiaddons/buildlink3.mk"
.include "../../x11/kxmlgui/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
