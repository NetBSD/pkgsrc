# $NetBSD: Makefile,v 1.2 2004/10/31 21:07:14 jdolecek Exp $

MODNAME=		ftp
PKGREVISION=		# empty
CATEGORIES+=		net
COMMENT=		PHP extension for FTP access

USE_BUILDLINK3=		YES

.include "../../lang/php/ext.mk"

CONFIGURE_ARGS+=	--enable-${MODNAME}

# adjust so that the pkg gets built with SSL support
LIBS+=			-lssl -lcrypto
CFLAGS+=		-DHAVE_OPENSSL_EXT

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
