# $NetBSD: Makefile,v 1.9 2004/12/03 15:15:08 wiz Exp $

PKGNAME=	${DISTNAME:S/cyrus-sasl/cy2-login/}
COMMENT=	Cyrus SASL LOGIN authentication plugin
SASL_PLUGIN=	yes

.include "../cyrus-sasl2/Makefile.common"

# We need to configure the PLAIN plugin as well since some of the important
# build variables for the LOGIN plugin are only set if PLAIN is configured.
#
CONFIGURE_ARGS+=	--enable-login
CONFIGURE_ARGS+=	--enable-plain

BUILD_DIRS=	${WRKSRC}/plugins
BUILD_TARGET=	liblogin.la

do-install:
	${INSTALL_DATA_DIR} ${PLUGINDIR}
	cd ${WRKSRC}/plugins && ${SHLIBTOOL} --mode=install \
		${INSTALL_PROGRAM} liblogin.la ${PLUGINDIR}

.include "../../mk/bsd.pkg.mk"
