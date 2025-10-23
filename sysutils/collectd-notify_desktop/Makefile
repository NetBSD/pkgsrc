# $NetBSD: Makefile,v 1.7 2025/10/23 20:39:15 wiz Exp $

COLLECTD_PACKAGE=	notify_desktop

COMMENT=		Statistics collection daemon - notify_desktop plugin
PKGREVISION=		6

.include "../../sysutils/libnotify/buildlink3.mk"
COLLECTD_LIB.notify=	${BUILDLINK_PREFIX.libnotify}

.include "../../sysutils/collectd/Makefile.common"

.include "../../mk/bsd.pkg.mk"
