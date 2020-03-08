# $NetBSD: Makefile,v 1.3 2020/03/08 16:48:44 wiz Exp $

GST_PLUGINS1_NAME=	sid
GST_PLUGINS1_DIRS=	ext/sidplay
GST_PLUGINS1_FLAGS=	sidplay

USE_LANGUAGES=	c c++

PKGREVISION= 1
.include "../../multimedia/gst-plugins1-ugly/Makefile.common"

.include "../../audio/libsidplay/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
