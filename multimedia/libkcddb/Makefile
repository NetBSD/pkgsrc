# $NetBSD: Makefile,v 1.59 2022/08/11 05:09:06 gutteridge Exp $

DISTNAME=	libkcddb-${KAPPSVER}
PKGREVISION=	10
CATEGORIES=	multimedia

HOMEPAGE=	https://www.kde.org/applications/multimedia/
COMMENT=	KDE CDDB library
LICENSE=	gnu-lgpl-v2 AND gnu-gpl-v2 AND gnu-fdl-v1.2

.include "../../meta-pkgs/kde/applications.mk"

BUILD_DEPENDS+=	kdoctools>=5.64.0:../../devel/kdoctools

USE_TOOLS+=	msgmerge

.include "../../audio/libmusicbrainz5/buildlink3.mk"
.include "../../devel/kio/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
