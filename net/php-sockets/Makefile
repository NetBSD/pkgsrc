# $NetBSD: Makefile,v 1.6 2006/02/05 23:10:29 joerg Exp $

MODNAME=		sockets
PKGREVISION=		1
CATEGORIES+=		net
COMMENT=		PHP extension for sockets support


CONFIGURE_ARGS+=	--enable-${MODNAME}=shared,${BUILDLINK_DIR}

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
