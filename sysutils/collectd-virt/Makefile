# $NetBSD: Makefile,v 1.26 2026/09/02 19:04:25 wiz Exp $

COLLECTD_PACKAGE=	virt

COMMENT=		Statistics collection daemon - virt plugin
PKGREVISION=		23

.include "../../sysutils/libvirt/buildlink3.mk"
COLLECTD_LIB.virt=	${BUILDLINK_PREFIX.libvirt}

.include "../../sysutils/collectd/Makefile.common"

.include "../../mk/bsd.pkg.mk"
