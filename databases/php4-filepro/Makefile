# $NetBSD: Makefile,v 1.2 2001/10/16 06:58:30 jlam Exp $

.include "../../www/php4/Makefile.module"

MODNAME=		filepro
CATEGORIES+=		databases
PHP_PKG_VERS=		# empty
COMMENT=		PHP4 extension for read-only filePro database access

USE_BUILDLINK_ONLY=	YES
CONFIGURE_ARGS+=	--with-${MODNAME}=shared

.include "../../mk/bsd.pkg.mk"
