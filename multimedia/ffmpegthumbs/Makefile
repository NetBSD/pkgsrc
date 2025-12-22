# $NetBSD: Makefile,v 1.80 2025/12/22 06:08:11 adam Exp $

DISTNAME=	ffmpegthumbs-${KAPPSVER}
PKGREVISION=	1
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
