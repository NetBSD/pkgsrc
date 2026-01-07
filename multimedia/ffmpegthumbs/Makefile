# $NetBSD: Makefile,v 1.81 2026/01/07 08:48:06 wiz Exp $

DISTNAME=	ffmpegthumbs-${KAPPSVER}
PKGREVISION=	2
CATEGORIES=	multimedia

HOMEPAGE=	https://kde.org/applications/multimedia/
COMMENT=	FFmpeg-based thumbnail creator for video files
LICENSE=	gnu-gpl-v2 AND gnu-fdl-v1.2 AND gnu-lgpl-v2

.include "../../meta-pkgs/kde/applications.mk"

USE_TOOLS+=	pkg-config

.include "../../audio/taglib/buildlink3.mk"
.include "../../devel/kf6-kio/buildlink3.mk"
.include "../../multimedia/ffmpeg7/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
