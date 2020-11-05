# $NetBSD: Makefile,v 1.27 2020/11/05 09:06:51 ryoon Exp $

DISTNAME=	libkomparediff2-${KAPPSVER}
PKGREVISION=	3
CATEGORIES=	devel

HOMEPAGE=	https://kde.org/applications/development/kompare/
COMMENT=	Library to compare files and strings
LICENSE=	gnu-gpl-v2 AND gnu-fdl-v1.2

.include "../../meta-pkgs/kde/applications.mk"

USE_TOOLS+=	msgmerge

.include "../../devel/kio/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
