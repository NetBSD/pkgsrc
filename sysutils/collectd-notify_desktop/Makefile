# $NetBSD: Makefile,v 1.3 2023/01/03 17:38:11 wiz Exp $

COLLECTD_PACKAGE=	notify_desktop

COMMENT=		Statistics collection daemon - notify_desktop plugin
PKGREVISION=		2

.include "../../sysutils/libnotify/buildlink3.mk"
COLLECTD_LIB.notify=	${BUILDLINK_PREFIX.libnotify}

.include "../../sysutils/collectd/Makefile.common"

.include "../../mk/bsd.pkg.mk"
