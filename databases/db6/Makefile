# $NetBSD: Makefile,v 1.5 2019/07/10 10:37:13 nia Exp $
#
# NOTE:
# When updating this package, a change in the minor (6.n -> 6.(n+1))
# usually incurs a shlib name change. Please make sure to update the
# ABI depends in buildlink3.mk and bump PKGREVISIONs for all dependencies.
# In particular, take care to include BDB_ACCEPTED=db6 packages.

DISTNAME=	db-6.2.23
PKGNAME=	${DISTNAME:S/db/db6/}
CATEGORIES=	databases
MASTER_SITES=	http://download.oracle.com/berkeley-db/

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://www.oracle.com/technetwork/database/database-technologies/berkeleydb/overview/index.html
COMMENT=	Berkeley DB version 6 from Oracle
LICENSE=	gnu-agpl-v3

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		pax
GNU_CONFIGURE=		yes
CONFIGURE_DIRS=		build_unix
CONFIGURE_SCRIPT=	../dist/configure
CONFIGURE_ARGS+=	--enable-compat185
CONFIGURE_ARGS+=	--enable-dbm
CONFIGURE_ARGS+=	--enable-cxx
CONFIGURE_ARGS+=	--includedir=${PREFIX}/include/db6
CONFIGURE_ARGS+=	--program-transform-name=s,db_,db6_,

OPSYSVARS+=		LIBSO_LIBS
LIBSO_LIBS.SunOS+=	-lnsl -lrt
CONFIGURE_ENV+=		LIBSO_LIBS=${LIBSO_LIBS:Q}

CHECK_PORTABILITY_SKIP=	test/xa/*/*.sh

# DB6 only want pthreads because it's really after POSIX 1003.1
# inter-process mutexes.  In this case, we only care to use the native
# threads.
PTHREAD_OPTS+=		native
.include "../../mk/pthread.buildlink3.mk"

.include "../../mk/bsd.prefs.mk"

PLIST_VARS+=	shlib

.if ${OPSYS} != "MirBSD"
PLIST.shlib=		yes
.endif

post-install:
	chown -R ${DOCOWN}:${DOCGRP} ${DESTDIR}${PREFIX}/share/doc/db6

.include "../../mk/bsd.pkg.mk"
