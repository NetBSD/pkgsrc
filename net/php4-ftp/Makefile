# $NetBSD: Makefile,v 1.1.1.1 2001/10/16 07:06:52 jlam Exp $

.include "../../www/php4/Makefile.module"

MODNAME=		ftp
CATEGORIES+=		net
PHP_PKG_VERS=		# empty
COMMENT=		PHP4 extension for FTP access

USE_BUILDLINK_ONLY=	YES
CONFIGURE_ARGS+=	--enable-${MODNAME}

.include "../../mk/bsd.pkg.mk"
