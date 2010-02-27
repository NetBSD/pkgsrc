# $NetBSD: Makefile,v 1.12 2010/02/27 03:35:12 taca Exp $

MODNAME=		ftp
CATEGORIES+=		net
COMMENT=		PHP extension for FTP access

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS=	php-ftp-[0-9]*

CONFIGURE_ARGS+=	--enable-${MODNAME}

# adjust so that the pkg gets built with SSL support
LIBS+=			-lssl -lcrypto
CFLAGS+=		-DHAVE_OPENSSL_EXT

.include "../../lang/php/ext.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
