# $NetBSD: Makefile,v 1.44 2006/07/19 23:02:13 wiz Exp $
#

DISTNAME=	gpgme-1.1.0
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.gnupg.org/gcrypt/gpgme/ \
		ftp://ftp.gnupg.org/gcrypt/alpha/gpgme/

MAINTAINER=	oishi@ims.ac.jp
HOMEPAGE=	http://www.gnupg.org/gpgme.html
COMMENT=	GnuPG Made Easy

DEPENDS+=		gnupg>=1.4.2:../../security/gnupg

USE_LIBTOOL=		YES
GNU_CONFIGURE=		YES
PTHREAD_OPTS+=		require
INFO_FILES=		YES

SUBST_CLASSES+=		pthread
SUBST_FILES.pthread=	gpgme/gpgme-config.in
SUBST_SED.pthread+=	-e 's,@PTHREAD_LIBS@,${PTHREAD_LDFLAGS} ${PTHREAD_LIBS},g'
SUBST_SED.pthread+=	-e 's,@PTHREAD_CFLAGS@,${PTHREAD_CFLAGS},g'
SUBST_STAGE.pthread=	post-patch

PKG_OPTIONS_VAR=        PKG_OPTIONS.gpgme
PKG_SUPPORTED_OPTIONS=	gpgsm
.include "../../mk/bsd.options.mk"

LIBS.SunOS+=		-lnsl -lsocket

# Avoid an ICE in gcc2 on sparc64
CONFIGURE_ENV+=		F77=${FALSE:Q}

# getenv_r is not detected correctly. It will be found
# in either base system or librfuncs
CONFIGURE_ENV+=		ac_cv_func_getenv_r=yes

TEST_TARGET=		check

.include "../../mk/pthread.buildlink3.mk"

.if ${PTHREAD_TYPE} == "native"
CONFIGURE_ARGS+=	--without-pth --without-pth-test
.endif

.include "../../security/libgpg-error/buildlink3.mk"

# we want the getenv_r() semantics of NetBSD-current
BUILDLINK_API_DEPENDS.librfuncs+=	librfuncs>=1.0.7nb1
.include "../../devel/librfuncs/buildlink3.mk"

##
## Option to build with gpgsm. This provides SMIME support
##
.if !empty(PKG_OPTIONS:Mgpgsm)
.  include "../../security/gnupg-devel/buildlink3.mk"
CONFIGURE_ARGS+=	--with-gpgsm=${BUILDLINK_PREFIX.gnupg-devel}/bin/gpgsm
.else
CONFIGURE_ARGS+=	--without-gpgsm
.endif

.include "../../mk/bsd.pkg.mk"
