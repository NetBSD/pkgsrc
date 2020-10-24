# $NetBSD: Makefile,v 1.1 2020/10/24 22:39:48 wiz Exp $

COLLECTD_PACKAGE=	varnish

COMMENT=		Statistics collection daemon - varnish plugin

.include "../../www/varnish/buildlink3.mk"
COLLECTD_LIB.varnish=	${BUILDLINK_PREFIX.varnish}

.include "../../sysutils/collectd/Makefile.common"

.include "../../mk/bsd.pkg.mk"
