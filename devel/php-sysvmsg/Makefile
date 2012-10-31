# $NetBSD: Makefile,v 1.2 2012/10/31 11:19:24 asau Exp $

MODNAME=		sysvmsg
CATEGORIES+=		devel
COMMENT=		PHP extension for SysV IPC Message Queues support

CONFIGURE_ARGS+=	--enable-${MODNAME}=shared,${BUILDLINK_DIR}

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
