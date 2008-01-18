# $NetBSD: Makefile,v 1.9 2008/01/18 05:08:48 tnn Exp $

MODNAME=		ftp
PKGREVISION=		1
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
