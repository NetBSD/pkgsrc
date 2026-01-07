# $NetBSD: Makefile,v 1.66 2026/01/07 08:48:09 wiz Exp $

DISTNAME=	libkcompactdisc-${KAPPSVER}
PKGREVISION=	1
CATEGORIES=	multimedia

HOMEPAGE=	https://kde.org/applications/multimedia/
COMMENT=	Library for interfacing with CDs
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2

USE_TOOLS+=	msgmerge

.include "../../meta-pkgs/kde/applications.mk"

.include "options.mk"

.include "../../devel/kf6-kcoreaddons/buildlink3.mk"
.include "../../devel/kf6-ki18n/buildlink3.mk"
.include "../../multimedia/phonon-qt6/buildlink3.mk"
.include "../../sysutils/kf6-solid/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
