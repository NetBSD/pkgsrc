# $NetBSD: Makefile,v 1.1.1.1 2004/10/31 19:30:30 jdolecek Exp $

MODNAME=		openssl
CATEGORIES+=		security
PKGREVISION=		# empty
COMMENT=		PHP extension for the OpenSSL library

USE_BUILDLINK3=		YES

CONFIGURE_ARGS+=	--with-${MODNAME}=shared,${BUILDLINK_PREFIX.openssl}

# the config test for -lssl fails to link in -lcrypto; just force it
# to succeed
CONFIGURE_ENV+=		ac_cv_lib_ssl_SSL_CTX_set_ssl_version=yes

post-extract:
	cd ${WRKSRC} && ln -s config0.m4 config.m4

.include "../../lang/php/ext.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
