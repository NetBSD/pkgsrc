# $NetBSD: Makefile,v 1.3 2003/11/12 03:39:42 jschauma Exp $

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
	cd ${WRKSRC}/plugins && \
	${PKGSHLIBTOOL} --mode=install \
		${INSTALL_PROGRAM} libntlm.la ${PLUGINDIR}

.include "../../security/openssl/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
