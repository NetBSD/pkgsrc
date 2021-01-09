# $NetBSD: Makefile,v 1.2 2021/01/09 19:50:53 gdt Exp $

COLLECTD_PACKAGE=	gps

COMMENT=		Statistics collection daemon - gps plugin
PKGREVISION=		1

.include "../../geography/gpsd/buildlink3.mk"
COLLECTD_LIB.gps=	${BUILDLINK_PREFIX.gpsd}

.include "../../sysutils/collectd/Makefile.common"

.include "../../mk/bsd.pkg.mk"
