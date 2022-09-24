# $NetBSD: Makefile,v 1.3 2022/09/24 11:07:34 wiz Exp $

COLLECTD_PACKAGE=	varnish

COMMENT=		Statistics collection daemon - varnish plugin

.include "../../www/varnish/buildlink3.mk"
COLLECTD_LIB.varnish=	${BUILDLINK_PREFIX.varnish}

.include "../../sysutils/collectd/Makefile.common"

.include "../../mk/bsd.pkg.mk"
