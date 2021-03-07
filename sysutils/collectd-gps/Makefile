# $NetBSD: Makefile,v 1.3 2021/03/07 14:19:41 wiz Exp $

COLLECTD_PACKAGE=	gps

COMMENT=		Statistics collection daemon - gps plugin

.include "../../geography/gpsd/buildlink3.mk"
COLLECTD_LIB.gps=	${BUILDLINK_PREFIX.gpsd}

.include "../../sysutils/collectd/Makefile.common"

.include "../../mk/bsd.pkg.mk"
