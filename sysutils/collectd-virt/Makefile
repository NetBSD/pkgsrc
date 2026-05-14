# $NetBSD: Makefile,v 1.25 2026/05/14 16:42:05 ryoon Exp $

COLLECTD_PACKAGE=	virt

COMMENT=		Statistics collection daemon - virt plugin
PKGREVISION=		22

.include "../../sysutils/libvirt/buildlink3.mk"
COLLECTD_LIB.virt=	${BUILDLINK_PREFIX.libvirt}

.include "../../sysutils/collectd/Makefile.common"

.include "../../mk/bsd.pkg.mk"
