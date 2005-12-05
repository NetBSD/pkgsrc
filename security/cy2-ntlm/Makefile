# $NetBSD: Makefile,v 1.13 2005/12/05 20:50:55 rillig Exp $

PKGNAME=	${DISTNAME:S/cyrus-sasl/cy2-ntlm/}
COMMENT=	Cyrus SASL NTLM authentication plugin
SASL_PLUGIN=	yes

.include "../../security/cyrus-sasl2/Makefile.common"

CONFIGURE_ARGS+=	--enable-ntlm
CONFIGURE_ARGS+=	--with-openssl=${SSLBASE}

BUILD_DIRS=	${WRKSRC}/plugins
BUILD_TARGET=	libntlm.la

.include "../../security/openssl/buildlink3.mk"

do-install:
	${INSTALL_DATA_DIR} ${PLUGINDIR}
	cd ${WRKSRC}/plugins && ${SHLIBTOOL} --mode=install \
		${INSTALL_PROGRAM} libntlm.la ${PLUGINDIR}

.include "../../mk/bsd.pkg.mk"
