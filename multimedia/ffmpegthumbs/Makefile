# $NetBSD: Makefile,v 1.24 2016/08/17 00:06:43 ryoon Exp $

DISTNAME=	ffmpegthumbs-${_KDE_VERSION}
PKGREVISION=	6
CATEGORIES=	multimedia
COMMENT=	FFmpeg-based thumbnail creator for video files

.include "../../meta-pkgs/kde4/Makefile.kde4"

.include "../../meta-pkgs/kde4/kde4.mk"

.include "../../multimedia/ffmpeg2/buildlink3.mk"
.include "../../x11/kdelibs4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
