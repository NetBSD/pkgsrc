# $NetBSD: Makefile,v 1.1 2011/09/17 11:32:03 obache Exp $

PKGNAME=	${DISTNAME:S/cyrus-sasl/cy2-scram/}
COMMENT=	Cyrus SASL SCRAM authentication plugin
SASL_PLUGIN=	yes

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../security/cyrus-sasl/Makefile.common"

CONFIGURE_ARGS+=	--enable-scram

BUILD_DIRS=	${WRKSRC}/plugins
BUILD_TARGET=	libscram.la

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PLUGINDIR}
	cd ${WRKSRC}/plugins && ${SHLIBTOOL} --mode=install		\
		${INSTALL_PROGRAM} libscram.la ${DESTDIR}${PLUGINDIR}

.include "../../mk/bsd.pkg.mk"
