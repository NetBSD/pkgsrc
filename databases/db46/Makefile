# $NetBSD: Makefile,v 1.6 2013/11/30 16:25:12 bsiegert Exp $

DISTNAME=	db-4.6.21
PKGNAME=	${DISTNAME:S/db/db46/}
CATEGORIES=	databases
MASTER_SITES=	http://download.oracle.com/berkeley-db/ \
		http://download-uk.oracle.com/berkeley-db/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.oracle.com/database/berkeley-db/db/index.html
COMMENT=	Berkeley DB version 4 from Oracle
LICENSE=	sleepycat-license # minus ASM stanza

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		pax rpcgen
GNU_CONFIGURE=		yes
CONFIGURE_DIRS=		build_unix
CONFIGURE_SCRIPT=	../dist/configure

CONFIGURE_ARGS+=	--enable-cxx
CONFIGURE_ARGS+=	--enable-rpc
CONFIGURE_ARGS+=	--enable-compat185
CONFIGURE_ARGS+=	--includedir=${PREFIX}/include/db46
CONFIGURE_ARGS+=	--program-transform-name=s,db_,db46_,

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

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "MirBSD"
PLIST_SRC=		PLIST.${OPSYS}
.endif

INSTALLATION_DIRS=	include/db46 lib share/doc/db46

post-install:
	chown -R ${DOCOWN}:${DOCGRP} ${DESTDIR}${PREFIX}/share/doc/db46

.include "../../mk/bsd.pkg.mk"
