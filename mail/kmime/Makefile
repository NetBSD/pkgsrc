# $NetBSD: Makefile,v 1.1 2019/11/17 05:32:25 markd Exp $

DISTNAME=	kmime-${KAPPSVER}
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
