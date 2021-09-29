# $NetBSD: Makefile,v 1.56 2021/09/29 19:01:02 adam Exp $

DISTNAME=	audiocd-kio-${KAPPSVER}
PKGREVISION=	4
CATEGORIES=	multimedia

HOMEPAGE=	https://kde.org/applications/multimedia/
COMMENT=	Kioslave for accessing audio CDs
LICENSE=	gnu-gpl-v2 AND gnu-fdl-v1.2

USE_TOOLS+=	msgmerge

.include "../../meta-pkgs/kde/applications.mk"

.include "../../audio/cdparanoia/buildlink3.mk"
.include "../../audio/flac/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../devel/kcmutils/buildlink3.mk"
.include "../../multimedia/libkcddb/buildlink3.mk"
.include "../../multimedia/libkcompactdisc/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
