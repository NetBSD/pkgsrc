# $NetBSD: Makefile,v 1.1.1.1 2001/10/16 07:05:00 jlam Exp $

.include "../../www/php4/Makefile.module"

MODNAME=		calendar
CATEGORIES+=		misc
PHP_PKG_VERS=		# empty
COMMENT=		PHP4 extension for calendar conversion support

USE_BUILDLINK_ONLY=	YES
CONFIGURE_ARGS+=	--enable-${MODNAME}

.include "../../mk/bsd.pkg.mk"
