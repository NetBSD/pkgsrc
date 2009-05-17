# $NetBSD: Makefile,v 1.11.8.1 2009/05/17 14:49:51 tron Exp $

PKGNAME=	${DISTNAME:S/cyrus-sasl/cy2-otp/}
COMMENT=	Cyrus SASL OTP authentication plugin
SASL_PLUGIN=	yes

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS=	cyrus-sasl<=2.1.19nb1

.include "../../security/cyrus-sasl/Makefile.common"

CONFIGURE_ARGS+=	--enable-otp
CONFIGURE_ARGS+=	--with-openssl=${SSLBASE:Q}

BUILD_DIRS=	${WRKSRC}/plugins
BUILD_TARGET=	libotp.la

.include "../../security/openssl/buildlink3.mk"

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PLUGINDIR}
	cd ${WRKSRC}/plugins && ${SHLIBTOOL} --mode=install		\
		${INSTALL_PROGRAM} libotp.la ${DESTDIR}${PLUGINDIR}

.include "../../mk/bsd.pkg.mk"
