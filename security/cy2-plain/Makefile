# $NetBSD: Makefile,v 1.4 2006/02/05 23:10:42 joerg Exp $

PKGNAME=	${DISTNAME:S/cyrus-sasl/cy2-plain/}
PKGREVISION=	1
COMMENT=	Cyrus SASL PLAIN authentication plugin
SASL_PLUGIN=	yes

CONFLICTS=	cyrus-sasl<=2.1.19nb1

.include "../../security/cyrus-sasl2/Makefile.common"

CONFIGURE_ARGS+=	--enable-plain

BUILD_DIRS=	${WRKSRC}/plugins
BUILD_TARGET=	libplain.la

do-install:
	${INSTALL_DATA_DIR} ${PLUGINDIR}
	cd ${WRKSRC}/plugins && ${SHLIBTOOL} --mode=install		\
		${INSTALL_PROGRAM} libplain.la ${PLUGINDIR}

.include "../../mk/bsd.pkg.mk"
