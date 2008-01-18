# $NetBSD: Makefile,v 1.18 2008/01/18 05:09:36 tnn Exp $

PKGNAME=	${DISTNAME:S/cyrus-sasl/cy2-ntlm/}
PKGREVISION=	1
COMMENT=	Cyrus SASL NTLM authentication plugin
SASL_PLUGIN=	yes

.include "../../security/cyrus-sasl/Makefile.common"

CONFIGURE_ARGS+=	--enable-ntlm
CONFIGURE_ARGS+=	--with-openssl=${SSLBASE:Q}

BUILD_DIRS=	${WRKSRC}/plugins
BUILD_TARGET=	libntlm.la

.include "../../security/openssl/buildlink3.mk"

do-install:
	${INSTALL_DATA_DIR} ${PLUGINDIR}
	cd ${WRKSRC}/plugins && ${SHLIBTOOL} --mode=install \
		${INSTALL_PROGRAM} libntlm.la ${PLUGINDIR}

.include "../../mk/bsd.pkg.mk"
