# $NetBSD: Makefile,v 1.5 2006/04/13 21:45:14 wiz Exp $

PKGNAME=	${DISTNAME:S/cyrus-sasl/cy2-anonymous/}
PKGREVISION=	1
COMMENT=	Cyrus SASL ANONYMOUS authentication plugin
SASL_PLUGIN=	yes

CONFLICTS=	cyrus-sasl<=2.1.19nb1

.include "../../security/cyrus-sasl/Makefile.common"

CONFIGURE_ARGS+=	--enable-anonymous

BUILD_DIRS=	${WRKSRC}/plugins
BUILD_TARGET=	libanonymous.la

do-install:
	${INSTALL_DATA_DIR} ${PLUGINDIR}
	cd ${WRKSRC}/plugins && ${SHLIBTOOL} --mode=install		\
		${INSTALL_PROGRAM} libanonymous.la ${PLUGINDIR}

.include "../../mk/bsd.pkg.mk"
