# $NetBSD: Makefile,v 1.63 2012/12/13 00:19:37 gdt Exp $
#
# NOTE:
# When updating this package, a change in the minor (4.n -> 4.(n+1))
# usually incurs a shlib name change. Please make sure to update the
# ABI depends in buildlink3.mk and bump PKGREVISIONs for all dependencies.
# In particular, take care to include BDB_ACCEPTED=db4 packages.

DISTNAME=	db-4.8.30
PKGNAME=	${DISTNAME:S/db/db4/}
CATEGORIES=	databases
MASTER_SITES=	http://download.oracle.com/berkeley-db/ \
		http://download-uk.oracle.com/berkeley-db/

#PATCHFILES=	patch.4.8.30.1
#PATCH_SITES=	http://www.oracle.com/technology/products/berkeley-db/db/update/4.8.30/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.oracle.com/database/berkeley-db/db/index.html
COMMENT=	Berkeley DB version 4 from Oracle
LICENSE=	sleepycat-public

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		pax
GNU_CONFIGURE=		yes
CONFIGURE_DIRS=		build_unix
CONFIGURE_SCRIPT=	../dist/configure
CONFIGURE_ARGS+=	--enable-compat185
CONFIGURE_ARGS+=	--enable-cxx
CONFIGURE_ARGS+=	--includedir=${PREFIX}/include/db4
CONFIGURE_ARGS+=	--program-transform-name=s,db_,db4_,

OPSYSVARS+=		LIBSO_LIBS
LIBSO_LIBS.SunOS+=	-lnsl -lrt
CONFIGURE_ENV+=		LIBSO_LIBS=${LIBSO_LIBS:Q}

# DB4 only want pthreads because it's really after POSIX 1003.1
# inter-process mutexes.  In this case, we only care to use the native
# threads.
PTHREAD_OPTS+=		native
.include "../../mk/pthread.buildlink3.mk"

INSTALLATION_DIRS=	include/db4 lib share/doc/db4

post-install:
	chown -R ${DOCOWN}:${DOCGRP} ${DESTDIR}${PREFIX}/share/doc/db4

.include "../../mk/bsd.pkg.mk"
