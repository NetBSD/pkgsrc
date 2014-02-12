# $NetBSD: Makefile,v 1.18 2014/02/12 23:18:31 tron Exp $

PKGNAME=	${DISTNAME:S/cyrus-sasl/cy2-digestmd5/}
PKGREVISION=	2
COMMENT=	Cyrus SASL DIGEST-MD5 authentication plugin
SASL_PLUGIN=	yes

CONFLICTS=	cyrus-sasl<=2.1.19nb1

.include "../../security/cyrus-sasl/Makefile.common"

CONFIGURE_ARGS+=	--enable-digest
CONFIGURE_ARGS+=	--with-rc4
CONFIGURE_ARGS+=	--with-openssl=${SSLBASE:Q}

BUILD_DIRS=	plugins
BUILD_TARGET=	libdigestmd5.la

.include "../../security/openssl/buildlink3.mk"

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PLUGINDIR}
	cd ${WRKSRC}/plugins && ${SHLIBTOOL} --mode=install		\
		${INSTALL_PROGRAM} libdigestmd5.la ${DESTDIR}${PLUGINDIR}

.include "../../mk/bsd.pkg.mk"
