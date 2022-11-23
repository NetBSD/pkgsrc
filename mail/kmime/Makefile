# $NetBSD: Makefile,v 1.16 2022/11/23 16:18:51 adam Exp $

DISTNAME=	kmime-${KAPPSVER}
PKGREVISION=	1
CATEGORIES=	mail

HOMEPAGE=	https://community.kde.org/KDE_PIM
COMMENT=	Library for handling mail messages and newsgroup articles
LICENSE=	gnu-lgpl-v2

.include "../../meta-pkgs/kde/applications.mk"

USE_TOOLS+=	msgmerge

.include "../../devel/ki18n/buildlink3.mk"
.include "../../textproc/kcodecs/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
