# $NetBSD: Makefile,v 1.1.1.1 2004/08/13 18:14:19 jlam Exp $

PKGNAME=	${DISTNAME:S/cyrus-sasl/cy2-otp/}
COMMENT=	Cyrus SASL OTP authentication plugin
SASL_PLUGIN=	yes

CONFLICTS=	cyrus-sasl<=2.1.19nb1

.include "../cyrus-sasl2/Makefile.common"

CONFIGURE_ARGS+=	--enable-otp
CONFIGURE_ARGS+=	--with-openssl=${SSLBASE}

BUILD_DIRS=	${WRKSRC}/plugins
ALL_TARGET=	libotp.la

.include "../../security/openssl/buildlink3.mk"

do-install:
	${INSTALL_DATA_DIR} ${PLUGINDIR}
	cd ${WRKSRC}/plugins && ${SHLIBTOOL} --mode=install		\
		${INSTALL_PROGRAM} libotp.la ${PLUGINDIR}

.include "../../mk/bsd.pkg.mk"
