# $NetBSD: Makefile,v 1.22 2023/12/13 13:40:42 zafer Exp $
#
# NOTE:
# When updating this package, a change in the minor (5.n -> 5.(n+1))
# usually incurs a shlib name change. Please make sure to update the
# ABI depends in buildlink3.mk and bump PKGREVISIONs for all dependencies.
# In particular, take care to include BDB_ACCEPTED=db5 packages.

DISTNAME=	db-5.3.28
PKGNAME=	${DISTNAME:S/db/db5/}
PKGREVISION=	2
CATEGORIES=	databases
MASTER_SITES=	https://download.oracle.com/berkeley-db/

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	https://www.oracle.com/database/berkeley-db/db/index.html
COMMENT=	Berkeley DB version 5 from Oracle
# NOTE: it is NOT a modified BSD in a common sense:
LICENSE=	sleepycat-public

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		pax
GNU_CONFIGURE=		yes
CONFIGURE_DIRS=		build_unix
CONFIGURE_SCRIPT=	../dist/configure
CONFIGURE_ARGS+=	--enable-compat185
CONFIGURE_ARGS+=	--enable-dbm
CONFIGURE_ARGS+=	--enable-cxx
CONFIGURE_ARGS+=	--includedir=${PREFIX}/include/db5
CONFIGURE_ARGS+=	--program-transform-name=s,db_,db5_,

OPSYSVARS+=		LIBSO_LIBS
LIBSO_LIBS.SunOS+=	-lnsl -lrt
CONFIGURE_ENV+=		LIBSO_LIBS=${LIBSO_LIBS:Q}

CHECK_PORTABILITY_SKIP=	test/xa/*/*.sh

# DB5 only want pthreads because it's really after POSIX 1003.1
# inter-process mutexes.  In this case, we only care to use the native
# threads.
PTHREAD_OPTS+=		native
.include "../../mk/pthread.buildlink3.mk"

.include "../../mk/bsd.prefs.mk"

PLIST_VARS+=	shlib

.if ${OPSYS} != "MirBSD"
PLIST.shlib=		yes
.endif

INSTALLATION_DIRS=	include/db5 lib share/doc/db5

post-install:
	chown -R ${DOCOWN}:${DOCGRP} ${DESTDIR}${PREFIX}/share/doc/db5

.include "../../mk/bsd.pkg.mk"
