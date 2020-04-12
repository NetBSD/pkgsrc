# $NetBSD: Makefile,v 1.39 2020/04/12 08:29:04 adam Exp $

PKGNAME=	gst-plugins1-${DISTNAME}
PKGREVISION=	3
COMMENT+=	(gstreamer plugin)

CONFIGURE_ARGS+=	--with-gstreamer

.include "../../net/libnice/Makefile.common"

BUILD_DIRS=	gst
INSTALL_DIRS=	gst

.include "../../net/libnice/buildlink3.mk"
.include "../../multimedia/gstreamer1/buildlink3.mk"
.include "../../multimedia/gst-plugins1-base/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
