# $NetBSD: Makefile,v 1.35 2021/12/08 16:01:59 adam Exp $

DISTNAME=	libkomparediff2-${KAPPSVER}
PKGREVISION=	4
CATEGORIES=	devel

HOMEPAGE=	https://kde.org/applications/development/kompare/
COMMENT=	Library to compare files and strings
LICENSE=	gnu-gpl-v2 AND gnu-fdl-v1.2

.include "../../meta-pkgs/kde/applications.mk"

USE_TOOLS+=	msgmerge

.include "../../devel/kio/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
