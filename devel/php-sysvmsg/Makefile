# $NetBSD: Makefile,v 1.3 2025/02/08 03:15:21 taca Exp $

MODNAME=		sysvmsg
PKGREVISION=		1
CATEGORIES+=		devel
COMMENT=		PHP extension for SysV IPC Message Queues support

CONFIGURE_ARGS+=	--enable-${MODNAME}=shared,${BUILDLINK_DIR}

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
