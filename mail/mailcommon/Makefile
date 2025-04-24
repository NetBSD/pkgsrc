# $NetBSD: Makefile,v 1.15 2025/04/24 14:14:57 wiz Exp $

DISTNAME=	mailcommon-${KAPPSVER}
PKGREVISION=	9
CATEGORIES=	mail

HOMEPAGE=	https://kontact.kde.org/
COMMENT=	KDE PIM library providing support for mail applications
LICENSE=	gnu-lgpl-v2.1 AND gnu-gpl-v2

.include "../../meta-pkgs/kde/applications.mk"

USE_TOOLS+=	msgmerge

.include "../../devel/boost-headers/buildlink3.mk"
.include "../../mail/mailimporter/buildlink3.mk"
.include "../../net/messagelib/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
