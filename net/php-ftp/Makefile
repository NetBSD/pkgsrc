# $NetBSD: Makefile,v 1.6 2006/02/05 23:10:29 joerg Exp $

MODNAME=		ftp
PKGREVISION=		1
CATEGORIES+=		net
COMMENT=		PHP extension for FTP access


CONFIGURE_ARGS+=	--enable-${MODNAME}

# adjust so that the pkg gets built with SSL support
LIBS+=			-lssl -lcrypto
CFLAGS+=		-DHAVE_OPENSSL_EXT

.include "../../lang/php/ext.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
