# $NetBSD: Makefile,v 1.15 2013/02/22 03:07:45 taca Exp $

MODNAME=		ftp
CATEGORIES+=		net
COMMENT=		PHP extension for FTP access

CONFLICTS=	php-ftp-[0-9]*

CONFIGURE_ARGS+=	--enable-${MODNAME}

# adjust so that the pkg gets built with SSL support
LIBS+=			-lssl -lcrypto
CFLAGS+=		-DHAVE_OPENSSL_EXT

.include "../../lang/php/ext.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
