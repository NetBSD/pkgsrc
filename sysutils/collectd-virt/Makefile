# $NetBSD: Makefile,v 1.6 2021/09/29 19:01:19 adam Exp $

COLLECTD_PACKAGE=	virt

COMMENT=		Statistics collection daemon - virt plugin
PKGREVISION=		3

.include "../../sysutils/libvirt/buildlink3.mk"
COLLECTD_LIB.virt=	${BUILDLINK_PREFIX.libvirt}

.include "../../sysutils/collectd/Makefile.common"

.include "../../mk/bsd.pkg.mk"
