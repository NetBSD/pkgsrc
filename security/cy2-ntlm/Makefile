# $NetBSD: Makefile,v 1.4 2004/01/08 22:13:14 jlam Exp $

PKGNAME=	${DISTNAME:S/cyrus-sasl/cy2-ntlm/}
PKGREVISION=	1
COMMENT=	Cyrus SASL NTLM authentication plugin
SASL_PLUGIN=	YES

.include "../cyrus-sasl2/Makefile.common"

CONFIGURE_ARGS+=	--enable-ntlm		# NTLM
CONFIGURE_ARGS+=	--with-openssl=${SSLBASE}

BUILD_DIRS=	${WRKSRC}/plugins
ALL_TARGET=	libntlm.la

do-install:
	${INSTALL_DATA_DIR} ${PLUGINDIR}
	cd ${WRKSRC}/plugins && \
	${PKGSHLIBTOOL} --mode=install \
		${INSTALL_PROGRAM} libntlm.la ${PLUGINDIR}

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
