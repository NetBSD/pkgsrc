# $NetBSD: Makefile,v 1.35 2019/05/21 14:48:17 wiz Exp $

PKGNAME=	gst-plugins1-${DISTNAME}
COMMENT+=	(gstreamer plugin)

CONFIGURE_ARGS+= --with-gstreamer

.include "../../net/libnice/Makefile.common"

BUILD_DIRS=	gst
INSTALL_DIRS=	gst

.include "../../net/libnice/buildlink3.mk"
.include "../../multimedia/gstreamer1/buildlink3.mk"
.include "../../multimedia/gst-plugins1-base/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
