# $NetBSD: Makefile,v 1.7 2026/09/27 11:38:32 tnn Exp $

COLLECTD_PACKAGE=	varnish

COMMENT=		Statistics collection daemon - varnish plugin
PKGREVISION=		3

.include "../../www/varnish/buildlink3.mk"
COLLECTD_LIB.varnish=	${BUILDLINK_PREFIX.varnish}

.include "../../sysutils/collectd/Makefile.common"

.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
