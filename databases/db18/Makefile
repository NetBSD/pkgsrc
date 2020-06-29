# $NetBSD: Makefile,v 1.1 2020/06/29 13:30:35 ryoon Exp $

DISTNAME=	db-18.1.40
PKGNAME=	${DISTNAME:S/db-/db18-/}
CATEGORIES=	databases
MASTER_SITES=	http://download.oracle.com/berkeley-db/

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://www.oracle.com/technetwork/database/database-technologies/berkeleydb/overview/index.html
COMMENT=	Berkeley DB version 18 from Oracle
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
CONFIGURE_ARGS+=	--includedir=${PREFIX}/include/db18
CONFIGURE_ARGS+=	--program-transform-name=s,db_,db18_,

OPSYSVARS+=		LIBSO_LIBS
LIBSO_LIBS.SunOS+=	-lnsl -lrt
CONFIGURE_ENV+=		LIBSO_LIBS=${LIBSO_LIBS:Q}

PTHREAD_OPTS+=		native
.include "../../mk/pthread.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
