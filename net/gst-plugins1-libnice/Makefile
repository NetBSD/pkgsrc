# $NetBSD: Makefile,v 1.37 2019/11/03 11:45:36 rillig Exp $

PKGNAME=	gst-plugins1-${DISTNAME}
PKGREVISION=	1
COMMENT+=	(gstreamer plugin)

CONFIGURE_ARGS+=	--with-gstreamer

.include "../../net/libnice/Makefile.common"

BUILD_DIRS=	gst
INSTALL_DIRS=	gst

.include "../../net/libnice/buildlink3.mk"
.include "../../multimedia/gstreamer1/buildlink3.mk"
.include "../../multimedia/gst-plugins1-base/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
