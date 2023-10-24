# $NetBSD: Makefile,v 1.33 2023/10/24 22:10:46 wiz Exp $

PKGNAME=	${DISTNAME:S/cyrus-sasl/cy2-ntlm/}
PKGREVISION=	1
COMMENT=	Cyrus SASL NTLM authentication plugin
SASL_PLUGIN=	yes

.include "../../security/cyrus-sasl/Makefile.common"

CONFIGURE_ARGS+=	--enable-ntlm
CONFIGURE_ARGS+=	--with-openssl=${SSLBASE:Q}

BUILD_DIRS=	plugins
BUILD_TARGET=	libntlm.la

.include "../../security/openssl/buildlink3.mk"

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PLUGINDIR}
	cd ${WRKSRC}/plugins && ${SHLIBTOOL} --mode=install \
		${INSTALL_PROGRAM} libntlm.la ${DESTDIR}${PLUGINDIR}

.include "../../mk/bsd.pkg.mk"
