# $NetBSD: Makefile,v 1.2 2004/02/08 03:00:29 jlam Exp $

PKGNAME=	${DISTNAME:S/cyrus-sasl/cy-login/}
COMMENT=	Cyrus SASL LOGIN authentication plugin
SASL_PLUGIN=	YES

.include "../cyrus-sasl/Makefile.common"

# We need to configure the PLAIN plugin as well since some of the important
# build variables for the LOGIN plugin are only set if PLAIN is configured.
#
CONFIGURE_ARGS+=	--enable-login		# LOGIN
CONFIGURE_ARGS+=	--enable-plain		# PLAIN
.if defined(USE_PAM)
.  include "../../security/PAM/buildlink2.mk"
BUILD_DEFS+=		USE_PAM
CONFIGURE_ARGS+=	--with-pam=${BUILDLINK_PREFIX.pam}
.endif

BUILD_DIRS=	${WRKSRC}/plugins
ALL_TARGET=	liblogin.la

do-install:
	cd ${WRKSRC}/plugins && \
	${LIBTOOL} --mode=install ${INSTALL_PROGRAM} liblogin.la ${PLUGINDIR}

.include "../../mk/bsd.pkg.mk"
