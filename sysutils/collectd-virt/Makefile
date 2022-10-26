# $NetBSD: Makefile,v 1.9 2022/10/26 10:31:58 wiz Exp $

COLLECTD_PACKAGE=	virt

COMMENT=		Statistics collection daemon - virt plugin
PKGREVISION=		6

.include "../../sysutils/libvirt/buildlink3.mk"
COLLECTD_LIB.virt=	${BUILDLINK_PREFIX.libvirt}

.include "../../sysutils/collectd/Makefile.common"

.include "../../mk/bsd.pkg.mk"
