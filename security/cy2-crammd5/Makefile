# $NetBSD: Makefile,v 1.10 2017/04/27 13:56:46 jperkin Exp $

PKGNAME=	${DISTNAME:S/cyrus-sasl/cy2-crammd5/}
PKGREVISION=	1
COMMENT=	Cyrus SASL CRAM-MD5 authentication plugin
SASL_PLUGIN=	yes

CONFLICTS=	cyrus-sasl<=2.1.19nb1

.include "../../security/cyrus-sasl/Makefile.common"

CONFIGURE_ARGS+=	--enable-cram

BUILD_DIRS=	plugins
BUILD_TARGET=	libcrammd5.la

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PLUGINDIR}
	cd ${WRKSRC}/plugins && ${SHLIBTOOL} --mode=install		\
		${INSTALL_PROGRAM} libcrammd5.la ${DESTDIR}${PLUGINDIR}

.include "../../mk/bsd.pkg.mk"
