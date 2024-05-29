# $NetBSD: Makefile,v 1.78 2024/05/29 16:33:49 adam Exp $
#

DISTNAME=	choqok-1.7.0
PKGREVISION=	6
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_KDE:=choqok/1.7/src/}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://choqok.kde.org/
COMMENT=	Twitter and StatusNet client for KDE
LICENSE=	gnu-gpl-v2

.include "../../meta-pkgs/kde/applications.mk"

TOOL_DEPENDS+=	kdoctools>=5.19.0:../../devel/kdoctools

USE_TOOLS+=	perl msgfmt pkg-config

DEPENDS=	qca2-qt5-ossl-[0-9]*:../../security/qca2-qt5-ossl

.include "../../devel/kcmutils/buildlink3.mk"
.include "../../devel/knotifyconfig/buildlink3.mk"
.include "../../devel/purpose/buildlink3.mk"
.include "../../security/qca2-qt5/buildlink3.mk"
.include "../../misc/attica-qt5/buildlink3.mk"
.include "../../misc/kemoticons/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../www/kdewebkit/buildlink3.mk"
.include "../../x11/kxmlgui/buildlink3.mk"
.include "../../x11/qt5-qtnetworkauth/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
