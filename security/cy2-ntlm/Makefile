# $NetBSD: Makefile,v 1.8 2004/08/01 21:02:13 jlam Exp $

PKGNAME=	${DISTNAME:S/cyrus-sasl/cy2-ntlm/}
COMMENT=	Cyrus SASL NTLM authentication plugin
SASL_PLUGIN=	yes

.include "../cyrus-sasl2/Makefile.common"

CONFIGURE_ARGS+=	--enable-ntlm		# NTLM
CONFIGURE_ARGS+=	--with-openssl=${SSLBASE}

BUILD_DIRS=	${WRKSRC}/plugins
ALL_TARGET=	libntlm.la

.include "../../security/openssl/buildlink3.mk"

do-install:
	${INSTALL_DATA_DIR} ${PLUGINDIR}
	cd ${WRKSRC}/plugins && \
	${SHLIBTOOL} --mode=install \
		${INSTALL_PROGRAM} libntlm.la ${PLUGINDIR}

.include "../../mk/bsd.pkg.mk"
