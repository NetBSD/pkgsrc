# $NetBSD: Makefile,v 1.6 2006/04/18 17:42:12 jlam Exp $

PKGNAME=	${DISTNAME:S/cyrus-sasl/cy2-plain/}
COMMENT=	Cyrus SASL PLAIN authentication plugin
SASL_PLUGIN=	yes

CONFLICTS=	cyrus-sasl<=2.1.19nb1

.include "../../security/cyrus-sasl/Makefile.common"

CONFIGURE_ARGS+=	--enable-plain

BUILD_DIRS=	${WRKSRC}/plugins
BUILD_TARGET=	libplain.la

do-install:
	${INSTALL_DATA_DIR} ${PLUGINDIR}
	cd ${WRKSRC}/plugins && ${SHLIBTOOL} --mode=install		\
		${INSTALL_PROGRAM} libplain.la ${PLUGINDIR}

.include "../../mk/bsd.pkg.mk"
