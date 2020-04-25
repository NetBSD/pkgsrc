# $NetBSD: Makefile,v 1.10 2020/04/25 17:19:19 rillig Exp $
#

GST_PLUGINS0.10_NAME=	libvisual
GST_PLUGINS0.10_DIRS=	ext/libvisual
GST_PLUGINS0.10_FLAGS=	libvisual
PKGREVISION=		2

.include "../../multimedia/gst-plugins0.10-base/Makefile.common"
SUBST_NOOP_OK.libs=	yes # does not depend on other plugins

.include "../../audio/libvisual/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
