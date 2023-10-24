# $NetBSD: Makefile,v 1.26 2023/10/24 22:10:46 wiz Exp $

PKGNAME=	${DISTNAME:S/cyrus-sasl/cy2-otp/}
PKGREVISION=	1
COMMENT=	Cyrus SASL OTP authentication plugin
SASL_PLUGIN=	yes

CONFLICTS=	cyrus-sasl<=2.1.19nb1

.include "../../security/cyrus-sasl/Makefile.common"

CONFIGURE_ARGS+=	--enable-otp
CONFIGURE_ARGS+=	--with-openssl=${SSLBASE:Q}

BUILD_DIRS=	plugins
#BUILD_TARGET=	libotp.la

.include "../../security/openssl/buildlink3.mk"

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PLUGINDIR}
	cd ${WRKSRC}/plugins && ${SHLIBTOOL} --mode=install		\
		${INSTALL_PROGRAM} libotp.la ${DESTDIR}${PLUGINDIR}

.include "../../mk/bsd.pkg.mk"
