# $NetBSD: Makefile,v 1.10 2008/06/12 02:14:41 joerg Exp $

MODNAME=		ftp
PKGREVISION=		1
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
