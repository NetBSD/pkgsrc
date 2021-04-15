# $NetBSD: Makefile,v 1.3 2021/04/15 11:23:12 ryoon Exp $

COLLECTD_PACKAGE=	nut

COMMENT=		Statistics collection daemon - nut plugin
PKGREVISION=		2

.include "../../sysutils/ups-nut/buildlink3.mk"
COLLECTD_LIB.upsclient=	${BUILDLINK_PREFIX.ups-nut}

.include "../../sysutils/collectd/Makefile.common"

.include "../../mk/bsd.pkg.mk"
