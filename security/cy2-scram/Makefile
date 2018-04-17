# $NetBSD: Makefile,v 1.9 2018/04/17 01:57:19 christos Exp $

PKGNAME=	${DISTNAME:S/cyrus-sasl/cy2-scram/}
#PKGREVISION=	4
COMMENT=	Cyrus SASL SCRAM authentication plugin
SASL_PLUGIN=	yes

.include "../../security/cyrus-sasl/Makefile.common"

CONFIGURE_ARGS+=	--enable-scram
CONFIGURE_ARGS+=	--with-openssl=${SSLBASE:Q}

BUILD_DIRS=	plugins
BUILD_TARGET=	libscram.la

.include "../../security/openssl/buildlink3.mk"

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PLUGINDIR}
	cd ${WRKSRC}/plugins && ${SHLIBTOOL} --mode=install		\
		${INSTALL_PROGRAM} libscram.la ${DESTDIR}${PLUGINDIR}

.include "../../mk/bsd.pkg.mk"
