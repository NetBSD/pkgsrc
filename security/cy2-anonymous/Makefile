# $NetBSD: Makefile,v 1.13 2020/05/23 12:21:48 rillig Exp $

PKGNAME=	${DISTNAME:S/cyrus-sasl/cy2-anonymous/}
COMMENT=	Cyrus SASL ANONYMOUS authentication plugin
SASL_PLUGIN=	yes

CONFLICTS=	cyrus-sasl<=2.1.19nb1

.include "../../security/cyrus-sasl/Makefile.common"

CONFIGURE_ARGS+=	--enable-anon

BUILD_DIRS=	plugins
BUILD_TARGET=	libanonymous.la

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PLUGINDIR}
	cd ${WRKSRC}/plugins && ${SHLIBTOOL} --mode=install		\
		${INSTALL_PROGRAM} libanonymous.la ${DESTDIR}${PLUGINDIR}

.include "../../mk/bsd.pkg.mk"
