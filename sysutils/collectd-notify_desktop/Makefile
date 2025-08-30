# $NetBSD: Makefile,v 1.6 2025/08/30 22:46:16 wiz Exp $

COLLECTD_PACKAGE=	notify_desktop

COMMENT=		Statistics collection daemon - notify_desktop plugin
PKGREVISION=		5

.include "../../sysutils/libnotify/buildlink3.mk"
COLLECTD_LIB.notify=	${BUILDLINK_PREFIX.libnotify}

.include "../../sysutils/collectd/Makefile.common"

.include "../../mk/bsd.pkg.mk"
