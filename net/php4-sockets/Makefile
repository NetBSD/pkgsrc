# $NetBSD: Makefile,v 1.1.1.1 2001/10/16 07:07:59 jlam Exp $

.include "../../www/php4/Makefile.module"

MODNAME=		sockets
CATEGORIES+=		net
PHP_PKG_VERS=		# empty
COMMENT=		PHP4 extension for sockets support

USE_BUILDLINK_ONLY=	YES
CONFIGURE_ARGS+=	--enable-${MODNAME}=shared,${BUILDLINK_DIR}

.include "../../mk/bsd.pkg.mk"
