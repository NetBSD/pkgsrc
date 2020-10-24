# $NetBSD: Makefile,v 1.1 2020/10/24 22:39:48 wiz Exp $

COLLECTD_PACKAGE=	xen
COLLECTD_PLUGINS=	xencpu

COMMENT=		Statistics collection daemon - xencpu plugin

COLLECTD_XEN?=	411

.include "../../sysutils/xentools${COLLECTD_XEN}/buildlink3.mk"
COLLECTD_LIB.xenctrl=	${BUILDLINK_PREFIX.xentools${COLLECTD_XEN}}

.include "../../sysutils/collectd/Makefile.common"

.include "../../mk/bsd.pkg.mk"
