# $NetBSD: Makefile,v 1.1.1.1 2003/03/19 22:28:23 jlam Exp $

PKGNAME=	${DISTNAME:S/cyrus-sasl/cy2-login/}
COMMENT=	Cyrus SASL LOGIN authentication plugin
SASL_PLUGIN=	YES

.include "../cyrus-sasl2/Makefile.common"

# We need to configure the PLAIN plugin as well since some of the important
# build variables for the LOGIN plugin are only set if PLAIN is configured.
#
CONFIGURE_ARGS+=	--enable-login		# LOGIN
CONFIGURE_ARGS+=	--enable-plain		# PLAIN

BUILD_DIRS=	${WRKSRC}/plugins
ALL_TARGET=	liblogin.la

do-install:
	cd ${WRKSRC}/plugins && \
	${PKGLIBTOOL} --mode=install ${INSTALL_PROGRAM} liblogin.la ${PLUGINDIR}

.include "../../mk/bsd.pkg.mk"
