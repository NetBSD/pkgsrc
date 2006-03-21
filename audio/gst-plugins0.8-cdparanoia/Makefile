# $NetBSD: Makefile,v 1.6 2006/03/21 06:00:43 jlam Exp $
#

GST_PLUGINS0.8_NAME=	cdparanoia
GST_PLUGINS0.8_DIR=	ext/cdparanoia

.include "../../multimedia/gst-plugins0.8/Makefile.common"
PKGREVISION=		5

CPPFLAGS+=		-I${BUILDLINK_PREFIX.cdparanoia}/include/cdparanoia

.include "../../audio/cdparanoia/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
