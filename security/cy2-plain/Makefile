# $NetBSD: Makefile,v 1.1.1.1 2004/08/13 18:14:32 jlam Exp $

PKGNAME=	${DISTNAME:S/cyrus-sasl/cy2-plain/}
COMMENT=	Cyrus SASL PLAIN authentication plugin
SASL_PLUGIN=	yes

CONFLICTS=	cyrus-sasl<=2.1.19nb1

.include "../cyrus-sasl2/Makefile.common"

CONFIGURE_ARGS+=	--enable-plain

BUILD_DIRS=	${WRKSRC}/plugins
ALL_TARGET=	libplain.la

do-install:
	${INSTALL_DATA_DIR} ${PLUGINDIR}
	cd ${WRKSRC}/plugins && ${SHLIBTOOL} --mode=install		\
		${INSTALL_PROGRAM} libplain.la ${PLUGINDIR}

.include "../../mk/bsd.pkg.mk"
