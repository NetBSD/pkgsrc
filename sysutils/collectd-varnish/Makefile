# $NetBSD: Makefile,v 1.2 2022/09/24 08:09:27 nia Exp $

COLLECTD_PACKAGE=	varnish

COMMENT=		Statistics collection daemon - varnish plugin

BROKEN+=		"fatal error: vapi/vsc.h: No such file or directory"

.include "../../www/varnish/buildlink3.mk"
COLLECTD_LIB.varnish=	${BUILDLINK_PREFIX.varnish}

.include "../../sysutils/collectd/Makefile.common"

.include "../../mk/bsd.pkg.mk"
