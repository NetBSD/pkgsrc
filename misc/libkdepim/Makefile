# $NetBSD: Makefile,v 1.8 2024/05/29 16:33:38 adam Exp $

DISTNAME=	libkdepim-${KAPPSVER}
PKGREVISION=	2
CATEGORIES=	misc

HOMEPAGE=	https://community.kde.org/KDE_PIM
COMMENT=	Libraries for KDE PIM applications
LICENSE=	gnu-lgpl-v2

.include "../../meta-pkgs/kde/applications.mk"

USE_TOOLS+=	msgmerge

.include "../../databases/kldap/buildlink3.mk"
.include "../../devel/boost-headers/buildlink3.mk"
.include "../../misc/akonadi-contacts/buildlink3.mk"
.include "../../misc/akonadi-search/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
