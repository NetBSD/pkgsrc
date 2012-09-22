# $NetBSD: Makefile,v 1.8 2012/09/22 12:36:45 obache Exp $
#

GST_PLUGINS0.10_NAME=	cdparanoia
GST_PLUGINS0.10_DIRS=	ext/cdparanoia
GST_PLUGINS0.10_FLAGS=	cdparanoia
PKGREVISION=		2

.include "../../multimedia/gst-plugins0.10-base/Makefile.common"

CPPFLAGS+=	-I${BUILDLINK_PREFIX.cdparanoia}/include/cdparanoia

BUILDLINK_API_DEPENDS.cdparanoia+= cdparanoia>=3.0.10.2
.include "../../audio/cdparanoia/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
