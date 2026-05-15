# $NetBSD: Makefile,v 1.99 2026/05/15 09:58:59 adam Exp $

DISTNAME=	libktorrent-${KAPPSVER}
PKGREVISION=	5
CATEGORIES=	net

HOMEPAGE=	https://apps.kde.org/ktorrent/
COMMENT=	BitTorrent protocol implementation
LICENSE=	gnu-gpl-v2

.include "../../meta-pkgs/kde/applications.mk"

USE_TOOLS+=	msgmerge pkg-config

LDFLAGS.SunOS+=	-lsocket

.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../devel/kf6-kio/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
