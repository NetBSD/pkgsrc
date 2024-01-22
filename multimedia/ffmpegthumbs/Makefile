# $NetBSD: Makefile,v 1.64 2024/01/22 13:17:01 ryoon Exp $

DISTNAME=	ffmpegthumbs-${KAPPSVER}
PKGREVISION=	4
CATEGORIES=	multimedia

HOMEPAGE=	https://kde.org/applications/multimedia/
COMMENT=	FFmpeg-based thumbnail creator for video files
LICENSE=	gnu-gpl-v2 AND gnu-fdl-v1.2 AND gnu-lgpl-v2

.include "../../meta-pkgs/kde/applications.mk"

USE_TOOLS+=	pkg-config

.include "../../audio/taglib/buildlink3.mk"
.include "../../devel/kio/buildlink3.mk"
.include "../../multimedia/ffmpeg5/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
