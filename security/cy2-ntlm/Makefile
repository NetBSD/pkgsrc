# $NetBSD: Makefile,v 1.1.1.1 2003/03/19 22:28:53 jlam Exp $

PKGNAME=	${DISTNAME:S/cyrus-sasl/cy2-ntlm/}
COMMENT=	Cyrus SASL NTLM authentication plugin
SASL_PLUGIN=	YES

.include "../cyrus-sasl2/Makefile.common"

CONFIGURE_ARGS+=	--enable-ntlm		# NTLM
CONFIGURE_ARGS+=	--with-openssl=${SSLBASE}

BUILD_DIRS=	${WRKSRC}/plugins
ALL_TARGET=	libntlm.la

do-install:
	cd ${WRKSRC}/plugins && \
	${PKGLIBTOOL} --mode=install ${INSTALL_PROGRAM} libntlm.la ${PLUGINDIR}

.include "../../security/openssl/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
