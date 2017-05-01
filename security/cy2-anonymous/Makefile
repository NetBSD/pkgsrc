# $NetBSD: Makefile,v 1.9.32.1 2017/05/01 09:36:48 bsiegert Exp $

PKGNAME=	${DISTNAME:S/cyrus-sasl/cy2-anonymous/}
PKGREVISION=	1
COMMENT=	Cyrus SASL ANONYMOUS authentication plugin
SASL_PLUGIN=	yes

CONFLICTS=	cyrus-sasl<=2.1.19nb1

.include "../../security/cyrus-sasl/Makefile.common"

CONFIGURE_ARGS+=	--enable-anonymous

BUILD_DIRS=	plugins
BUILD_TARGET=	libanonymous.la

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PLUGINDIR}
	cd ${WRKSRC}/plugins && ${SHLIBTOOL} --mode=install		\
		${INSTALL_PROGRAM} libanonymous.la ${DESTDIR}${PLUGINDIR}

.include "../../mk/bsd.pkg.mk"
