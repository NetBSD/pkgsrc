# $NetBSD: Makefile,v 1.7 2004/03/26 02:27:49 wiz Exp $

MODNAME=		ftp
PKGREVISION=		3
CATEGORIES+=		net
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
