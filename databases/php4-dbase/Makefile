# $NetBSD: Makefile,v 1.1.1.1 2001/10/16 06:45:48 jlam Exp $

.include "../php4/Makefile.module"

MODNAME=		dbase
CATEGORIES+=		databases
PHP_PKG_VERS=		# empty
COMMENT=		PHP4 extension for dBase database access

USE_BUILDLINK_ONLY=	YES
CONFIGURE_ARGS+=	--with-${MODNAME}=shared

.include "../../mk/bsd.pkg.mk"
