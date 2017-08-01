# $NetBSD: Makefile,v 1.82 2017/08/01 11:48:20 ryoon Exp $

DISTNAME=	gpgme-1.8.0
PKGREVISION=	1
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.gnupg.org/gcrypt/gpgme/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnupg.org/related_software/gpgme/
COMMENT=	GnuPG Made Easy
LICENSE=	gnu-gpl-v2

USE_LANGUAGES+=		c c++

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
PTHREAD_OPTS+=		require
INFO_FILES=		yes

# turn off swig/python detection; there is no configure flag as of 1.8.0
# https://dev.gnupg.org/T3057
CONFIGURE_ENV+=		ac_cv_path_SWIG=

SUBST_CLASSES+=		pthread
SUBST_FILES.pthread=	src/gpgme-config.in
SUBST_SED.pthread+=	-e 's,@PTHREAD_LIBS@,${PTHREAD_LDFLAGS} ${PTHREAD_LIBS},g'
SUBST_SED.pthread+=	-e 's,@PTHREAD_CFLAGS@,${PTHREAD_CFLAGS},g'
SUBST_STAGE.pthread=	post-patch

LIBS.SunOS+=		-lnsl -lsocket

# getenv_r is not detected correctly. It will be found
# in either base system or librfuncs
CONFIGURE_ENV+=		ac_cv_func_getenv_r=yes

# 17 errors as of 1.8.0
# https://dev.gnupg.org/T3056
TEST_TARGET=		check

.include "../../mk/pthread.buildlink3.mk"

.include "options.mk"

CONFIGURE_ENV.HPUX+=	ac_cv_lib_pthread_pthread_create=yes

.include "../../mk/bsd.prefs.mk"

# TLS is unsupported on NetBSD<=5, but causes crashes on -current too
#.if !empty(MACHINE_PLATFORM:MNetBSD-[0-5].*-*)
.if !empty(MACHINE_PLATFORM:MNetBSD-*-*)
CONFIGURE_ENV+=		gpgme_cv_tls_works=no
.endif

# we want the getenv_r() semantics of NetBSD-current
BUILDLINK_API_DEPENDS.librfuncs+=	librfuncs>=1.0.7nb1
.include "../../devel/librfuncs/buildlink3.mk"
BUILDLINK_API_DEPENDS.libassuan+=	libassuan>=2.0.2
.include "../../security/libassuan2/buildlink3.mk"
BUILDLINK_API_DEPENDS.libgpg-error+=	libgpg-error>=1.17
.include "../../security/libgpg-error/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
_UNWRAP_FILES=
