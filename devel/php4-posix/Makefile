# $NetBSD: Makefile,v 1.2 2001/10/16 06:58:32 jlam Exp $

.include "../../www/php4/Makefile.module"

MODNAME=		posix
CATEGORIES+=		devel
PHP_PKG_VERS=		# empty
COMMENT=		PHP4 extension for POSIX-like functions

USE_BUILDLINK_ONLY=	YES
CONFIGURE_ARGS+=	--enable-${MODNAME}=shared

.include "../../mk/bsd.pkg.mk"
