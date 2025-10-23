# $NetBSD: Makefile,v 1.3 2025/10/23 06:07:25 wiz Exp $

COLLECTD_PACKAGE=	xen
COLLECTD_PLUGINS=	xencpu

COMMENT=		Statistics collection daemon - xencpu plugin

COLLECTD_XEN?=	418

.include "../../sysutils/xentools${COLLECTD_XEN}/buildlink3.mk"
COLLECTD_LIB.xenctrl=	${BUILDLINK_PREFIX.xentools${COLLECTD_XEN}}

.include "../../sysutils/collectd/Makefile.common"

.include "../../mk/bsd.pkg.mk"
