# $NetBSD: Makefile,v 1.5 2025/05/17 23:23:11 gdt Exp $

COLLECTD_PACKAGE=	gps

COMMENT=		Statistics collection daemon - gps plugin
PKGREVISION=		2

.include "../../geography/gpsd/buildlink3.mk"
COLLECTD_LIB.gps=	${BUILDLINK_PREFIX.gpsd}

.include "../../sysutils/collectd/Makefile.common"

.include "../../mk/bsd.pkg.mk"
