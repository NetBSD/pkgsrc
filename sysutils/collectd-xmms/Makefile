# $NetBSD: Makefile,v 1.1 2020/10/24 22:39:49 wiz Exp $

COLLECTD_PACKAGE=	xmms

COMMENT=		Statistics collection daemon - xmms plugin

.include "../../audio/xmms/buildlink3.mk"
COLLECTD_LIB.xmms=	${BUILDLINK_PREFIX.xmms}

.include "../../sysutils/collectd/Makefile.common"

.include "../../mk/bsd.pkg.mk"
