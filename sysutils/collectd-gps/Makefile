# $NetBSD: Makefile,v 1.6 2025/11/23 13:27:42 gdt Exp $

COLLECTD_PACKAGE=	gps

COMMENT=		Statistics collection daemon - gps plugin
PKGREVISION=		3

.include "../../geography/gpsd/buildlink3.mk"
COLLECTD_LIB.gps=	${BUILDLINK_PREFIX.gpsd}

.include "../../sysutils/collectd/Makefile.common"

.include "../../mk/bsd.pkg.mk"
