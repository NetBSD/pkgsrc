# $NetBSD: Makefile,v 1.5 2006/03/07 06:30:55 joerg Exp $
#

GST_PLUGINS0.8_NAME=	cdparanoia
GST_PLUGINS0.8_DIR=	ext/cdparanoia

.include "../../multimedia/gst-plugins0.8/Makefile.common"
PKGREVISION=		4

CPPFLAGS+=		-I${BUILDLINK_PREFIX.cdparanoia}/include/cdparanoia

.include "../../audio/cdparanoia/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
