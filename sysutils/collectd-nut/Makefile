# $NetBSD: Makefile,v 1.1 2020/10/24 22:39:47 wiz Exp $

COLLECTD_PACKAGE=	nut

COMMENT=		Statistics collection daemon - nut plugin

.include "../../sysutils/ups-nut/buildlink3.mk"
COLLECTD_LIB.upsclient=	${BUILDLINK_PREFIX.ups-nut}

.include "../../sysutils/collectd/Makefile.common"

.include "../../mk/bsd.pkg.mk"
