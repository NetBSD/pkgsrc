# $NetBSD: Makefile,v 1.6 2004/01/13 19:44:59 jdolecek Exp $

MODNAME=		ftp
CATEGORIES+=		net
PKGREVISION=		2
COMMENT=		PHP4 extension for FTP access

USE_BUILDLINK2=		YES
DISTINFO_FILE=		${.CURDIR}/distinfo

.include "../../www/php4/Makefile.module"

CONFIGURE_ARGS+=	--enable-${MODNAME}

# adjust so that the pkg gets built with SSL support
LIBS+=			-lssl -lcrypto
CFLAGS+=		-DHAVE_OPENSSL_EXT

.include "../../security/openssl/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
