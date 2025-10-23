# $NetBSD: Makefile,v 1.87 2025/10/23 20:38:37 wiz Exp $

DISTNAME=	libkcddb-${KAPPSVER}
PKGREVISION=	11
CATEGORIES=	multimedia

HOMEPAGE=	https://www.kde.org/applications/multimedia/
COMMENT=	KDE CDDB library
LICENSE=	gnu-lgpl-v2 AND gnu-gpl-v2 AND gnu-fdl-v1.2

.include "../../meta-pkgs/kde/applications.mk"

TOOL_DEPENDS+=	kdoctools>=5.64.0:../../devel/kdoctools

USE_TOOLS+=	msgmerge

.include "../../audio/libmusicbrainz5/buildlink3.mk"
.include "../../devel/kcmutils/buildlink3.mk"
.include "../../devel/kio/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
