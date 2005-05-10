# $NetBSD: Makefile,v 1.38 2005/05/10 16:24:48 drochner Exp $

DISTNAME=		db-4.3.28
PKGNAME=		${DISTNAME:S/db/db4/}
CATEGORIES=		databases
MASTER_SITES=		ftp://ftp.sleepycat.com/releases/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.sleepycat.com/
COMMENT=		Berkeley DB version 4 from Sleepycat Software

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_DIRS=		${WRKSRC}/build_unix
BUILD_DIRS=		${CONFIGURE_DIRS}
CONFIGURE_SCRIPT=	../dist/configure

CONFIGURE_ARGS+=	--enable-cxx
CONFIGURE_ARGS+=	--enable-rpc
CONFIGURE_ARGS+=	--enable-shared
CONFIGURE_ARGS+=	--enable-compat185
CONFIGURE_ARGS+=	--includedir=${PREFIX}/include/db4
CONFIGURE_ARGS+=	--program-transform-name=s,db_,db4_,

.include "../../mk/bsd.prefs.mk"
.include "options.mk"

# NetBSD-sparc64-1.6*'s f77 makes configure failing and as f77 is not
# needed for this package the following does no harm on other platform.
CONFIGURE_ENV+=		F77=${FALSE}

OPSYSVARS+=		LIBSO_LIBS
LIBSO_LIBS.Interix+=	-lrpclib
LIBS.Interix+=		-lrpclib # needed for in-tree programs, too
LIBSO_LIBS.SunOS+=	-lnsl -lrt
CONFIGURE_ENV+=		LIBSO_LIBS="${LIBSO_LIBS}"

# DB4 only want pthreads because it's really after POSIX 1003.1
# inter-process mutexes.  In this case, we only care to use the native
# threads.  We also only care if we're using a non-GCC compiler since
# we have code to use GCC assembly for mutexes instead of 1003.1
# mutexes.
#
.include "../../mk/compiler.mk"
.if !empty(PKGSRC_COMPILER:Mgcc)
CONFIGURE_ENV+=		ac_cv_lib_pthread_main=no
.else
PTHREAD_OPTS+=		native
.  include "../../mk/pthread.buildlink3.mk"
.endif

post-install:
	${CHOWN} -R ${DOCOWN}:${DOCGRP} ${PREFIX}/share/doc/db4

.include "../../mk/bsd.pkg.mk"
