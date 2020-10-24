# $NetBSD: Makefile,v 1.8 2020/10/24 22:39:47 wiz Exp $

COLLECTD_PACKAGE=	notify-email

COMMENT=		Statistics collection daemon - notify_email plugin

.include "../../mail/libesmtp/buildlink3.mk"
COLLECTD_LIB.esmtp=	${BUILDLINK_PREFIX.libesmtp}

.include "../../sysutils/collectd/Makefile.common"

.include "../../mk/bsd.pkg.mk"
