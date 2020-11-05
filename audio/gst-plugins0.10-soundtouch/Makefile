# $NetBSD: Makefile,v 1.4 2020/11/05 09:07:27 ryoon Exp $

GST_PLUGINS0.10_NAME=	soundtouch
GST_PLUGINS0.10_DIRS=	ext/soundtouch

USE_LANGUAGES=		c c++
PKGREVISION= 3
.include "../../multimedia/gst-plugins0.10-bad/Makefile.common"
USE_LANGUAGES=		c c++

.include "../../audio/soundtouch/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
