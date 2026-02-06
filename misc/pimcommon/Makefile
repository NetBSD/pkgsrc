# $NetBSD: Makefile,v 1.21 2026/02/06 10:05:23 wiz Exp $

DISTNAME=	pimcommon-${KAPPSVER}
PKGREVISION=	3
CATEGORIES=	misc

HOMEPAGE=	https://community.kde.org/KDE_PIM
COMMENT=	Common libraries for KDE PIM
LICENSE=	gnu-lgpl-v2

.include "../../meta-pkgs/kde/applications.mk"

USE_TOOLS+=	msgmerge

.include "../../databases/kldap/buildlink3.mk"
.include "../../devel/kf6-purpose/buildlink3.mk"
.include "../../devel/qt6-qttools/buildlink3.mk"
.include "../../mail/kimap/buildlink3.mk"
.include "../../misc/akonadi-contacts/buildlink3.mk"
.include "../../misc/akonadi-search/buildlink3.mk"
.include "../../misc/libkdepim/buildlink3.mk"
.include "../../net/kf6-knewstuff/buildlink3.mk"
.include "../../textproc/ktextaddons/buildlink3.mk"
.include "../../x11/plasma6-plasma-activities/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
