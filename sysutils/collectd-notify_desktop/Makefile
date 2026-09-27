# $NetBSD: Makefile,v 1.9 2026/09/27 11:38:32 tnn Exp $

COLLECTD_PACKAGE=	notify_desktop

COMMENT=		Statistics collection daemon - notify_desktop plugin
PKGREVISION=		8

.include "../../sysutils/libnotify/buildlink3.mk"
COLLECTD_LIB.notify=	${BUILDLINK_PREFIX.libnotify}

.include "../../sysutils/collectd/Makefile.common"

.include "../../mk/bsd.pkg.mk"
