# $NetBSD: Makefile,v 1.60 2009/12/15 20:17:33 drochner Exp $
#

DISTNAME=	gpgme-1.1.8
PKGREVISION=	2
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.gnupg.org/gcrypt/gpgme/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnupg.org/related_software/gpgme/
COMMENT=	GnuPG Made Easy

PKG_DESTDIR_SUPPORT=	user-destdir

PKG_OPTIONS_VAR=        PKG_OPTIONS.gpgme
PKG_SUPPORTED_OPTIONS=	gpgsm
PKG_SUGGESTED_OPTIONS=	gpgsm
.include "../../mk/bsd.options.mk"
.if empty(PKG_OPTIONS:Mgpgsm)
DEPENDS+=		gnupg>=1.4.2:../../security/gnupg
.endif

USE_LIBTOOL=		YES
GNU_CONFIGURE=		YES
PTHREAD_OPTS+=		require
INFO_FILES=		YES

SUBST_CLASSES+=		pthread
SUBST_FILES.pthread=	src/gpgme-config.in
SUBST_SED.pthread+=	-e 's,@PTHREAD_LIBS@,${PTHREAD_LDFLAGS} ${PTHREAD_LIBS},g'
SUBST_SED.pthread+=	-e 's,@PTHREAD_CFLAGS@,${PTHREAD_CFLAGS},g'
SUBST_STAGE.pthread=	post-patch

LIBS.SunOS+=		-lnsl -lsocket

# Avoid an ICE in gcc2 on sparc64
CONFIGURE_ENV+=		F77=${FALSE:Q}

# getenv_r is not detected correctly. It will be found
# in either base system or librfuncs
CONFIGURE_ENV+=		ac_cv_func_getenv_r=yes
CONFIGURE_ENV+=		ac_cv_func_funopen=yes

TEST_TARGET=		check

.include "../../mk/pthread.buildlink3.mk"

.if ${PTHREAD_TYPE} == "native"
CONFIGURE_ARGS+=	--without-pth --without-pth-test
.endif

BUILDLINK_API_DEPENDS.libgpg-error+=	libgpg-error>=1.4
.include "../../security/libgpg-error/buildlink3.mk"

# we want the getenv_r() semantics of NetBSD-current
BUILDLINK_API_DEPENDS.librfuncs+=	librfuncs>=1.0.7nb1
.include "../../devel/librfuncs/buildlink3.mk"

##
## Option to build with gpgsm. This provides SMIME support
##
.if !empty(PKG_OPTIONS:Mgpgsm)
.  include "../../security/gnupg2/buildlink3.mk"
CONFIGURE_ARGS+=	--with-gpgsm=${BUILDLINK_PREFIX.gnupg2}/bin/gpgsm
CONFIGURE_ARGS+=	--with-gpg=${BUILDLINK_PREFIX.gnupg2}/bin/gpg2
REPLACE_SH+=		tests/gpg/pinentry
.else
CONFIGURE_ARGS+=	--without-gpgsm
CONFIGURE_ARGS+=	--without-gpgconf
.endif

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "HPUX"
CONFIGURE_ENV+=		ac_cv_lib_pthread_pthread_create=yes
.endif

.include "../../mk/bsd.pkg.mk"
