# $NetBSD: Makefile,v 1.106 2026/11/07 19:11:54 wiz Exp $

DISTNAME=	libktorrent-${KAPPSVER}
PKGREVISION=	3
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
