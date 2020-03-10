# $NetBSD: Makefile,v 1.5 2020/03/10 22:08:55 wiz Exp $

DISTNAME=	kidentitymanagement-${KAPPSVER}
PKGREVISION=	2
CATEGORIES=	misc

HOMEPAGE=	https://community.kde.org/KDE_PIM
COMMENT=	Library for managing identitites
LICENSE=	gnu-lgpl-v2

.include "../../meta-pkgs/kde/applications.mk"

USE_TOOLS+=	msgmerge

.include "../../textproc/kpimtextedit/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
