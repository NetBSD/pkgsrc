# $NetBSD: Makefile,v 1.1 2026/09/06 10:05:15 markd Exp $

DISTNAME=	kmime-${KF6VER}
CATEGORIES=	mail

HOMEPAGE=	https://community.kde.org/Frameworks
COMMENT=	Library for handling mail messages and newsgroup articles
LICENSE=	gnu-lgpl-v2

.include "../../meta-pkgs/kde/kf6.mk"

USE_TOOLS+=	msgmerge

.include "../../devel/kf6-ki18n/buildlink3.mk"
.include "../../devel/qt6-qttools/buildlink3.mk"
.include "../../textproc/kf6-kcodecs/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
