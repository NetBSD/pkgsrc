# $NetBSD: Makefile,v 1.6 2026/09/02 19:04:25 wiz Exp $

COLLECTD_PACKAGE=	varnish

COMMENT=		Statistics collection daemon - varnish plugin
PKGREVISION=		2

.include "../../www/varnish/buildlink3.mk"
COLLECTD_LIB.varnish=	${BUILDLINK_PREFIX.varnish}

.include "../../sysutils/collectd/Makefile.common"

.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
