# $NetBSD: Makefile,v 1.60 2024/11/01 12:53:44 wiz Exp $

DISTNAME=	libkcompactdisc-${KAPPSVER}
PKGREVISION=	4
CATEGORIES=	multimedia

HOMEPAGE=	https://kde.org/applications/multimedia/
COMMENT=	Library for interfacing with CDs
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2

USE_TOOLS+=	msgmerge

.include "../../meta-pkgs/kde/applications.mk"

.include "options.mk"

.include "../../devel/kcoreaddons/buildlink3.mk"
.include "../../devel/ki18n/buildlink3.mk"
.include "../../multimedia/phonon-qt5/buildlink3.mk"
.include "../../sysutils/solid/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
