# $NetBSD: Makefile,v 1.2 2001/10/16 06:58:34 jlam Exp $

.include "../../www/php4/Makefile.module"

MODNAME=		mcrypt
CATEGORIES+=		security
PHP_PKG_VERS=		# empty
COMMENT=		PHP4 extension for the mcrypt crypto algorithms library

CONFIGURE_ARGS+=	--with-${MODNAME}=shared,${BUILDLINK_DIR}

.include "../../security/libmcrypt/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
