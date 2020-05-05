# $NetBSD: Makefile,v 1.21 2020/05/05 14:08:15 tm Exp $

MODNAME=		ftp
CATEGORIES+=		net
COMMENT=		PHP extension for FTP access
PKGREVISION=		2

CONFLICTS=	php-ftp-[0-9]*

CONFIGURE_ARGS+=	--enable-${MODNAME}

# adjust so that the pkg gets built with SSL support
LIBS+=			-lssl -lcrypto
CFLAGS+=		-DHAVE_OPENSSL_EXT -DHAVE_FTP_SSL

.include "../../lang/php/ext.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
