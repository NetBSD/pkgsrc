# $NetBSD: Makefile,v 1.10 2022/11/23 16:21:04 adam Exp $

COLLECTD_PACKAGE=	virt

COMMENT=		Statistics collection daemon - virt plugin
PKGREVISION=		7

.include "../../sysutils/libvirt/buildlink3.mk"
COLLECTD_LIB.virt=	${BUILDLINK_PREFIX.libvirt}

.include "../../sysutils/collectd/Makefile.common"

.include "../../mk/bsd.pkg.mk"
