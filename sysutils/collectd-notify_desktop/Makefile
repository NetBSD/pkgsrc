# $NetBSD: Makefile,v 1.2 2021/12/08 16:06:27 adam Exp $

COLLECTD_PACKAGE=	notify_desktop

COMMENT=		Statistics collection daemon - notify_desktop plugin
PKGREVISION=		1

.include "../../sysutils/libnotify/buildlink3.mk"
COLLECTD_LIB.notify=	${BUILDLINK_PREFIX.libnotify}

.include "../../sysutils/collectd/Makefile.common"

.include "../../mk/bsd.pkg.mk"
