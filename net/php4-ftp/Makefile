# $NetBSD: Makefile,v 1.8 2004/04/20 19:19:23 jdolecek Exp $

MODNAME=		ftp
PKGREVISION=		# empty
CATEGORIES+=		net
COMMENT=		PHP4 extension for FTP access

USE_BUILDLINK2=		YES

.include "../../www/php4/Makefile.module"

CONFIGURE_ARGS+=	--enable-${MODNAME}

# adjust so that the pkg gets built with SSL support
LIBS+=			-lssl -lcrypto
CFLAGS+=		-DHAVE_OPENSSL_EXT

.include "../../security/openssl/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
