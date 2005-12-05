# $NetBSD: Makefile,v 1.5 2005/12/05 20:50:48 rillig Exp $

MODNAME=		ftp
CATEGORIES+=		net
COMMENT=		PHP extension for FTP access


CONFIGURE_ARGS+=	--enable-${MODNAME}

# adjust so that the pkg gets built with SSL support
LIBS+=			-lssl -lcrypto
CFLAGS+=		-DHAVE_OPENSSL_EXT

.include "../../lang/php/ext.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
