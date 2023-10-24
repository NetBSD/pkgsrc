# $NetBSD: Makefile,v 1.9 2023/10/24 22:11:05 wiz Exp $

COLLECTD_PACKAGE=	notify-email

COMMENT=		Statistics collection daemon - notify_email plugin
PKGREVISION=		1

.include "../../mail/libesmtp/buildlink3.mk"
COLLECTD_LIB.esmtp=	${BUILDLINK_PREFIX.libesmtp}

.include "../../sysutils/collectd/Makefile.common"

.include "../../mk/bsd.pkg.mk"
