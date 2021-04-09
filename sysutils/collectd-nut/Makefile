# $NetBSD: Makefile,v 1.2 2021/04/09 06:55:04 wiz Exp $

COLLECTD_PACKAGE=	nut

COMMENT=		Statistics collection daemon - nut plugin
PKGREVISION=		1

.include "../../sysutils/ups-nut/buildlink3.mk"
COLLECTD_LIB.upsclient=	${BUILDLINK_PREFIX.ups-nut}

.include "../../sysutils/collectd/Makefile.common"

.include "../../mk/bsd.pkg.mk"
