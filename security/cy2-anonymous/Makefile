# $NetBSD: Makefile,v 1.3 2005/12/05 20:50:55 rillig Exp $

PKGNAME=	${DISTNAME:S/cyrus-sasl/cy2-anonymous/}
COMMENT=	Cyrus SASL ANONYMOUS authentication plugin
SASL_PLUGIN=	yes

CONFLICTS=	cyrus-sasl<=2.1.19nb1

.include "../../security/cyrus-sasl2/Makefile.common"

CONFIGURE_ARGS+=	--enable-anonymous

BUILD_DIRS=	${WRKSRC}/plugins
BUILD_TARGET=	libanonymous.la

do-install:
	${INSTALL_DATA_DIR} ${PLUGINDIR}
	cd ${WRKSRC}/plugins && ${SHLIBTOOL} --mode=install		\
		${INSTALL_PROGRAM} libanonymous.la ${PLUGINDIR}

.include "../../mk/bsd.pkg.mk"
