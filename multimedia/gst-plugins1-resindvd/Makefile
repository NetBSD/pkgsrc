# $NetBSD: Makefile,v 1.6 2020/05/22 12:43:53 adam Exp $

GST_PLUGINS1_NAME=	resindvd
GST_PLUGINS1_FLAGS=	dvdnav
GST_PLUGINS1_DIRS=	ext/resindvd

PKGREVISION= 2
.include "../../multimedia/gst-plugins1-bad/Makefile.common"

.include "../../multimedia/libdvdnav/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
