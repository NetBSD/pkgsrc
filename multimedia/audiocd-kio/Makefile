# $NetBSD: Makefile,v 1.100 2026/11/07 19:11:52 wiz Exp $

DISTNAME=	audiocd-kio-${KAPPSVER}
PKGREVISION=	3
CATEGORIES=	multimedia

HOMEPAGE=	https://kde.org/applications/multimedia/
COMMENT=	Kioslave for accessing audio CDs
LICENSE=	gnu-gpl-v2 AND gnu-fdl-v1.2

USE_TOOLS+=	msgmerge

.include "../../meta-pkgs/kde/applications.mk"

.include "../../audio/cdparanoia/buildlink3.mk"
.include "../../audio/flac/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../devel/kf6-kcmutils/buildlink3.mk"
.include "../../multimedia/libkcddb/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
