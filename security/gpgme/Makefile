# $NetBSD: Makefile,v 1.26 2004/11/03 15:35:08 jmmv Exp $
#

DISTNAME=	gpgme-1.0.1
PKGREVISION=	1
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.gnupg.org/gcrypt/gpgme/ \
		ftp://ftp.gnupg.org/gcrypt/alpha/gpgme/

MAINTAINER=	oishi@ims.ac.jp
HOMEPAGE=	http://www.gnupg.org/gpgme.html
COMMENT=	GnuPG Made Easy

USE_BUILDLINK3=		YES
USE_LIBTOOL=		YES
GNU_CONFIGURE=		YES
PTHREAD_OPTS+=		require

PKG_OPTIONS_VAR=        PKG_OPTIONS.gpgme
PKG_SUPPORTED_OPTIONS=	gpgsm
.include "../../mk/bsd.options.mk"

LIBS.SunOS+=		-lnsl -lsocket

# Avoid an ICE in gcc2 on sparc64
CONFIGURE_ENV+=		F77=${FALSE}

# getenv_r is not detected correctly. It will be found
# in either base system or librfuncs
CONFIGURE_ENV+=		ac_cv_func_getenv_r=yes

TEST_TARGET=		check

.include "../../mk/pthread.buildlink3.mk"

.if ${PTHREAD_TYPE} == "native"
CONFIGURE_ARGS+=	--without-pth --without-pth-test
.endif

INFO_FILES=		gpgme.info

.include "../../security/libgpg-error/buildlink3.mk"
.if ${OPSYS} != "SunOS"
.include "../../devel/librfuncs/buildlink3.mk"
.endif

##
## Option to build with gpgsm. This provides SMIME support
##
.if !empty(PKG_OPTIONS:Mgpgsm)
.include "../../security/gnupg-devel/buildlink3.mk"
CONFIGURE_ARGS+=	--with-gpgsm=${BUILDLINK_PREFIX.gnupg-devel}/bin/gpgsm
CONFIGURE_ARGS+=	--with-gpg=${BUILDLINK_PREFIX.gnupg-devel}/bin/gpg2
.else
DEPENDS+=		gnupg>=1.2.2:../../security/gnupg
.endif

.include "../../mk/bsd.pkg.mk"
