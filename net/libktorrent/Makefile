# $NetBSD: Makefile,v 1.82 2024/05/29 16:33:57 adam Exp $

DISTNAME=	libktorrent-${KAPPSVER}
PKGREVISION=	2
CATEGORIES=	net

HOMEPAGE=	https://apps.kde.org/ktorrent/
COMMENT=	BitTorrent protocol implementation
LICENSE=	gnu-gpl-v2

.include "../../meta-pkgs/kde/applications.mk"

USE_TOOLS+=	msgmerge pkg-config

.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../devel/kio/buildlink3.mk"
.include "../../security/qca2-qt5/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
