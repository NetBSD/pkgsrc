# $NetBSD: Makefile,v 1.1.1.1 2003/09/01 16:37:36 jdolecek Exp $

MODNAME=		openssl
CATEGORIES+=		security
PKGREVISION=		# empty
COMMENT=		PHP4 extension for the OpenSSL library

USE_BUILDLINK2=		YES

.include "../../www/php4/Makefile.module"

CONFIGURE_ARGS+=	--with-${MODNAME}=shared,${BUILDLINK_PREFIX.openssl}

.include "../../security/openssl/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
