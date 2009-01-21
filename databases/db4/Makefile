# $NetBSD: Makefile,v 1.57 2009/01/21 15:44:32 drochner Exp $
#
# NOTE:
# When updating this package, a change in the minor (4.n -> 4.(n+1))
# usually incurs a shlib name change. Please make sure to update the
# ABI depends in buildlink3.mk and bump PKGREVISIONs for all dependencies.
# In particular, take care to include BDB_ACCEPTED=db4 packages.

DISTNAME=	db-4.7.25
PKGNAME=	${DISTNAME:S/db/db4/}.3
CATEGORIES=	databases
MASTER_SITES=	http://download.oracle.com/berkeley-db/ \
		http://download-uk.oracle.com/berkeley-db/

# doesn't apply due to line endings, included as patch-ba
#PATCHFILES=	patch.4.7.25.1
#PATCH_SITES=	http://www.oracle.com/technology/products/berkeley-db/db/update/4.7.25/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.oracle.com/database/berkeley-db/db/index.html
COMMENT=	Berkeley DB version 4 from Oracle

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		pax
GNU_CONFIGURE=		yes
CONFIGURE_DIRS=		build_unix
CONFIGURE_SCRIPT=	../dist/configure

CONFIGURE_ARGS+=	--enable-cxx
CONFIGURE_ARGS+=	--enable-rpc
CONFIGURE_ARGS+=	--enable-compat185
CONFIGURE_ARGS+=	--includedir=${PREFIX}/include/db4
CONFIGURE_ARGS+=	--program-transform-name=s,db_,db4_,

# NetBSD-sparc64-1.6*'s f77 makes configure failing and as f77 is not
# needed for this package the following does no harm on other platform.
CONFIGURE_ENV+=		F77=${FALSE:Q}

# Along with a hack in patch-ab, this forces shlib detection via
# the pkgsrc-supplied libtool only.
CONFIGURE_ENV+=		LIBTOOL_PROG=${LIBTOOL:Q}\ ${LIBTOOL_FLAGS:Q}

OPSYSVARS+=		LIBSO_LIBS
LIBSO_LIBS.Interix+=	-lrpclib
LIBS.Interix+=		-lrpclib # needed for in-tree programs, too
LIBSO_LIBS.SunOS+=	-lnsl -lrt
CONFIGURE_ENV+=		LIBSO_LIBS=${LIBSO_LIBS:Q}

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

INSTALLATION_DIRS=	include/db4 lib share/doc/db4

post-install:
	chown -R ${DOCOWN}:${DOCGRP} ${DESTDIR}${PREFIX}/share/doc/db4

.include "../../mk/bsd.pkg.mk"
