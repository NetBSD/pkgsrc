# $NetBSD: Makefile,v 1.7 2006/02/05 23:10:42 joerg Exp $

PKGNAME=	${DISTNAME:S/cyrus-sasl/cy2-digestmd5/}
PKGREVISION=	1
COMMENT=	Cyrus SASL DIGEST-MD5 authentication plugin
SASL_PLUGIN=	yes

CONFLICTS=	cyrus-sasl<=2.1.19nb1

.include "../../security/cyrus-sasl2/Makefile.common"

CONFIGURE_ARGS+=	--enable-digest
CONFIGURE_ARGS+=	--with-rc4
CONFIGURE_ARGS+=	--with-openssl=${SSLBASE:Q}

BUILD_DIRS=	${WRKSRC}/plugins
BUILD_TARGET=	libdigestmd5.la

.include "../../security/openssl/buildlink3.mk"

do-install:
	${INSTALL_DATA_DIR} ${PLUGINDIR}
	cd ${WRKSRC}/plugins && ${SHLIBTOOL} --mode=install		\
		${INSTALL_PROGRAM} libdigestmd5.la ${PLUGINDIR}

.include "../../mk/bsd.pkg.mk"
