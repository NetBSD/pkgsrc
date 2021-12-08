# $NetBSD: Makefile,v 1.6 2021/12/08 16:03:12 adam Exp $

GST_PLUGINS0.10_NAME=	soundtouch
GST_PLUGINS0.10_DIRS=	ext/soundtouch

USE_LANGUAGES=		c c++
PKGREVISION= 5
.include "../../multimedia/gst-plugins0.10-bad/Makefile.common"
USE_LANGUAGES=		c c++

.include "../../audio/soundtouch/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
