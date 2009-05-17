# $NetBSD: Makefile,v 1.19.8.1 2009/05/17 14:49:50 tron Exp $

PKGNAME=	${DISTNAME:S/cyrus-sasl/cy2-ntlm/}
COMMENT=	Cyrus SASL NTLM authentication plugin
SASL_PLUGIN=	yes

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../security/cyrus-sasl/Makefile.common"

CONFIGURE_ARGS+=	--enable-ntlm
CONFIGURE_ARGS+=	--with-openssl=${SSLBASE:Q}

BUILD_DIRS=	${WRKSRC}/plugins
BUILD_TARGET=	libntlm.la

.include "../../security/openssl/buildlink3.mk"

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PLUGINDIR}
	cd ${WRKSRC}/plugins && ${SHLIBTOOL} --mode=install \
		${INSTALL_PROGRAM} libntlm.la ${DESTDIR}${PLUGINDIR}

.include "../../mk/bsd.pkg.mk"
