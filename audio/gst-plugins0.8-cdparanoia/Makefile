# $NetBSD: Makefile,v 1.7 2006/04/17 14:52:10 wiz Exp $
#

GST_PLUGINS0.8_NAME=	cdparanoia
GST_PLUGINS0.8_DIR=	ext/cdparanoia

.include "../../multimedia/gst-plugins0.8/Makefile.common"
PKGREVISION=		6

CPPFLAGS+=		-I${BUILDLINK_PREFIX.cdparanoia}/include/cdparanoia

.include "../../audio/cdparanoia/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
