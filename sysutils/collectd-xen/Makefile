# $NetBSD: Makefile,v 1.2 2022/06/29 17:03:29 wiz Exp $

COLLECTD_PACKAGE=	xen
COLLECTD_PLUGINS=	xencpu

COMMENT=		Statistics collection daemon - xencpu plugin

COLLECTD_XEN?=	415

.include "../../sysutils/xentools${COLLECTD_XEN}/buildlink3.mk"
COLLECTD_LIB.xenctrl=	${BUILDLINK_PREFIX.xentools${COLLECTD_XEN}}

.include "../../sysutils/collectd/Makefile.common"

.include "../../mk/bsd.pkg.mk"
