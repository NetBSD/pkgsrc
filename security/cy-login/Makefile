# $NetBSD: Makefile,v 1.8 2005/02/07 11:35:47 jlam Exp $

PKGNAME=	${DISTNAME:S/cyrus-sasl/cy-login/}
PKGREVISION=	1
COMMENT=	Cyrus SASL LOGIN authentication plugin
SASL_PLUGIN=	YES

.include "../cyrus-sasl/Makefile.common"

# We need to configure the PLAIN plugin as well since some of the important
# build variables for the LOGIN plugin are only set if PLAIN is configured.
#
CONFIGURE_ARGS+=	--enable-login		# LOGIN
CONFIGURE_ARGS+=	--enable-plain		# PLAIN

PKG_OPTIONS_VAR=	PKG_OPTIONS.cy-login
PKG_SUPPORTED_OPTIONS=	PAM
.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:MPAM)
.  include "../../mk/pam.buildlink3.mk"
CONFIGURE_ARGS+=	--with-pam=${PAMBASE}
.endif

BUILD_DIRS=	${WRKSRC}/plugins
BUILD_TARGET=	liblogin.la

do-install:
	cd ${WRKSRC}/plugins && \
	${LIBTOOL} --mode=install ${INSTALL_PROGRAM} liblogin.la ${PLUGINDIR}

.include "../../mk/bsd.pkg.mk"
