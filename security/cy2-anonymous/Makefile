# $NetBSD: Makefile,v 1.1.1.1 2004/08/13 18:12:58 jlam Exp $

PKGNAME=	${DISTNAME:S/cyrus-sasl/cy2-anonymous/}
COMMENT=	Cyrus SASL ANONYMOUS authentication plugin
SASL_PLUGIN=	yes

CONFLICTS=	cyrus-sasl<=2.1.19nb1

.include "../cyrus-sasl2/Makefile.common"

CONFIGURE_ARGS+=	--enable-anonymous

BUILD_DIRS=	${WRKSRC}/plugins
ALL_TARGET=	libanonymous.la

do-install:
	${INSTALL_DATA_DIR} ${PLUGINDIR}
	cd ${WRKSRC}/plugins && ${SHLIBTOOL} --mode=install		\
		${INSTALL_PROGRAM} libanonymous.la ${PLUGINDIR}

.include "../../mk/bsd.pkg.mk"
