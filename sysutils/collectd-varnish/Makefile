# $NetBSD: Makefile,v 1.5 2025/10/23 20:39:15 wiz Exp $

COLLECTD_PACKAGE=	varnish

COMMENT=		Statistics collection daemon - varnish plugin
PKGREVISION=		1

.include "../../www/varnish/buildlink3.mk"
COLLECTD_LIB.varnish=	${BUILDLINK_PREFIX.varnish}

.include "../../sysutils/collectd/Makefile.common"

.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
