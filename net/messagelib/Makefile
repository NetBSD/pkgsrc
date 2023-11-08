# $NetBSD: Makefile,v 1.3 2023/11/08 13:20:31 wiz Exp $

DISTNAME=	messagelib-${KAPPSVER}
PKGREVISION=	2
CATEGORIES=	net

HOMEPAGE=	https://kontact.kde.org/
COMMENT=	KDE PIM messaging library
LICENSE=	gnu-lgpl-v2.1 AND gnu-gpl-v2

.include "../../meta-pkgs/kde/applications.mk"

USE_TOOLS+=	msgmerge

.include "../../mk/bsd.prefs.mk"

.include "../../devel/boost-headers/buildlink3.mk"
.if ${OPSYS} != "Linux"
.include "../../devel/libinotify/buildlink3.mk"
.endif
.include "../../mail/kmailtransport/buildlink3.mk"
.include "../../mail/kmbox/buildlink3.mk"
.include "../../misc/kidentitymanagement/buildlink3.mk"
.include "../../misc/libgravatar/buildlink3.mk"
.include "../../security/qca2-qt5/buildlink3.mk"
.include "../../x11/qt5-qtwebengine/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
