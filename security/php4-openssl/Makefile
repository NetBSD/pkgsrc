# $NetBSD: Makefile,v 1.3 2003/11/12 03:39:43 jschauma Exp $

MODNAME=		openssl
CATEGORIES+=		security
PKGREVISION=		1
COMMENT=		PHP4 extension for the OpenSSL library

USE_BUILDLINK2=		YES

.include "../../www/php4/Makefile.module"

CONFIGURE_ARGS+=	--with-${MODNAME}=shared,${BUILDLINK_PREFIX.openssl}

# the config test for -lssl fails to link in -lcrypto; just force it
# to succeed
CONFIGURE_ENV+=		ac_cv_lib_ssl_SSL_CTX_set_ssl_version=yes

post-extract:
	cd ${WRKSRC} && ln -s config0.m4 config.m4

.include "../../security/openssl/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
