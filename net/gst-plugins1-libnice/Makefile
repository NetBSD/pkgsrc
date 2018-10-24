# $NetBSD: Makefile,v 1.31 2018/10/24 21:11:54 leot Exp $

PKGNAME=	gst-plugins1-${DISTNAME}
PKGREVISION=	6
COMMENT+=	(gstreamer plugin)

CONFIGURE_ARGS+= --with-gstreamer

.include "../../net/libnice/Makefile.common"

BUILD_DIRS=	gst
INSTALL_DIRS=	gst

.include "../../net/libnice/buildlink3.mk"
.include "../../multimedia/gstreamer1/buildlink3.mk"
.include "../../multimedia/gst-plugins1-base/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
