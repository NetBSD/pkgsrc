# $NetBSD: Makefile,v 1.4 2002/11/05 07:33:17 martti Exp $

MODNAME=		ftp
CATEGORIES+=		net
PKGREVISION=		# empty
COMMENT=		PHP4 extension for FTP access

USE_BUILDLINK2=		YES

.include "../../www/php4/Makefile.module"

CONFIGURE_ARGS+=	--enable-${MODNAME}

.include "../../mk/bsd.pkg.mk"
