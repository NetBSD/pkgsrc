# $NetBSD: Makefile,v 1.1 2020/10/24 22:39:46 wiz Exp $

COLLECTD_PACKAGE=	gps

COMMENT=		Statistics collection daemon - gps plugin

.include "../../geography/gpsd/buildlink3.mk"
COLLECTD_LIB.gps=	${BUILDLINK_PREFIX.gpsd}

.include "../../sysutils/collectd/Makefile.common"

.include "../../mk/bsd.pkg.mk"
