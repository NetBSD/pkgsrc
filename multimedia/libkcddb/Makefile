# $NetBSD: Makefile,v 1.65 2023/04/03 20:21:15 nros Exp $

DISTNAME=	libkcddb-${KAPPSVER}
PKGREVISION=	4
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
