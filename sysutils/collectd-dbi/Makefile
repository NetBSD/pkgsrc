# $NetBSD: Makefile,v 1.5 2020/10/24 22:39:45 wiz Exp $

COLLECTD_PACKAGE=	dbi

COMMENT=		Statistics collection daemon - dbi plugin

.include "../../databases/libdbi/buildlink3.mk"
COLLECTD_LIB.dbi=	${BUILDLINK_PREFIX.libdbi}

.include "../../sysutils/collectd/Makefile.common"

.include "../../mk/bsd.pkg.mk"
