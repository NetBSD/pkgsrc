# $NetBSD: Makefile,v 1.1 2020/10/24 22:39:48 wiz Exp $

COLLECTD_PACKAGE=	tokyotyrant

COMMENT=		Statistics collection daemon - tokyotyrant plugin

.include "../../databases/tokyotyrant/buildlink3.mk"
COLLECTD_LIB.tokyotyrant=	${BUILDLINK_PREFIX.tokyotyrant}

.include "../../sysutils/collectd/Makefile.common"

.include "../../mk/bsd.pkg.mk"
