# $NetBSD: Makefile,v 1.6 2004/03/29 05:47:31 jlam Exp $

PKGNAME=	${DISTNAME:S/cyrus-sasl/cy2-login/}
PKGREVISION=	1
COMMENT=	Cyrus SASL LOGIN authentication plugin
SASL_PLUGIN=	yes

.include "../cyrus-sasl2/Makefile.common"

# We need to configure the PLAIN plugin as well since some of the important
# build variables for the LOGIN plugin are only set if PLAIN is configured.
#
CONFIGURE_ARGS+=	--enable-login		# LOGIN
CONFIGURE_ARGS+=	--enable-plain		# PLAIN

BUILD_DIRS=	${WRKSRC}/plugins
ALL_TARGET=	liblogin.la

do-install:
	${INSTALL_DATA_DIR} ${PLUGINDIR}
	cd ${WRKSRC}/plugins && \
	${SHLIBTOOL} --mode=install \
		${INSTALL_PROGRAM} liblogin.la ${PLUGINDIR}

.include "../../mk/bsd.pkg.mk"
