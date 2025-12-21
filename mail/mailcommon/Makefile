# $NetBSD: Makefile,v 1.18 2025/12/21 13:20:56 markd Exp $

DISTNAME=	mailcommon-${KAPPSVER}
CATEGORIES=	mail

HOMEPAGE=	https://kontact.kde.org/
COMMENT=	KDE PIM library providing support for mail applications
LICENSE=	gnu-lgpl-v2.1 AND gnu-gpl-v2

.include "../../meta-pkgs/kde/applications.mk"

USE_TOOLS+=	msgmerge

.include "../../mail/mailimporter/buildlink3.mk"
.include "../../net/messagelib/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
