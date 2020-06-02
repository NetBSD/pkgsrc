# $NetBSD: Makefile,v 1.3 2020/06/02 08:23:11 adam Exp $

GST_PLUGINS0.10_NAME=	soundtouch
GST_PLUGINS0.10_DIRS=	ext/soundtouch

USE_LANGUAGES=		c c++
PKGREVISION= 2
.include "../../multimedia/gst-plugins0.10-bad/Makefile.common"
USE_LANGUAGES=		c c++

.include "../../audio/soundtouch/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
