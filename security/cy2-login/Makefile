# $NetBSD: Makefile,v 1.17 2017/04/27 13:56:47 jperkin Exp $

PKGNAME=	${DISTNAME:S/cyrus-sasl/cy2-login/}
PKGREVISION=	1
COMMENT=	Cyrus SASL LOGIN authentication plugin
SASL_PLUGIN=	yes

.include "../../security/cyrus-sasl/Makefile.common"

# We need to configure the PLAIN plugin as well since some of the important
# build variables for the LOGIN plugin are only set if PLAIN is configured.
#
CONFIGURE_ARGS+=	--enable-login
CONFIGURE_ARGS+=	--enable-plain

BUILD_DIRS=	plugins
BUILD_TARGET=	liblogin.la

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PLUGINDIR}
	cd ${WRKSRC}/plugins && ${SHLIBTOOL} --mode=install \
		${INSTALL_PROGRAM} liblogin.la ${DESTDIR}${PLUGINDIR}

.include "../../mk/bsd.pkg.mk"
