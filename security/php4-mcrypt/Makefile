# $NetBSD: Makefile,v 1.1.1.1 2001/10/16 06:05:41 jlam Exp $

.include "../php4/Makefile.module"

MODNAME=		mcrypt
CATEGORIES+=		security
PHP_PKG_VERS=		# empty
COMMENT=		PHP4 extension for the mcrypt crypto algorithms library

CONFIGURE_ARGS+=	--with-${MODNAME}=shared,${BUILDLINK_DIR}

.include "../../security/libmcrypt/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
