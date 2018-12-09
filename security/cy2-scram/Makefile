# $NetBSD: Makefile,v 1.10 2018/12/09 21:05:35 adam Exp $

PKGNAME=	${DISTNAME:S/cyrus-sasl/cy2-scram/}
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
