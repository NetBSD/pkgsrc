# $NetBSD: Makefile,v 1.26 2024/05/22 08:44:31 adam Exp $

.include "../../databases/openldap/Makefile.version"

# get the version from libraries/liblmdb/lmdb.h
PKGNAME=	lmdb-0.9.33
CATEGORIES=	databases

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Symas Lightning Memory-Mapped Database

USE_GCC_RUNTIME=	yes
USE_TOOLS+=		gmake
USE_LIBTOOL=		yes

BUILD_DIRS=		libraries/liblmdb
MAKE_FLAGS+=		CC=${CC:Q}
MAKE_FLAGS+=		XCFLAGS=${CFLAGS:Q}\ -D_SEM_SEMUN_UNDEFINED
INSTALL_MAKE_FLAGS+=	prefix=${PREFIX}

INSTALLATION_DIRS+=	bin
INSTALLATION_DIRS+=	include
INSTALLATION_DIRS+=	lib
INSTALLATION_DIRS+=	${PKGMANDIR}/man1

CHECK_PORTABILITY_SKIP=	configure
TEST_TARGET=		test

.include "../../mk/bsd.prefs.mk"

LDFLAGS+=	-lpthread

.if ${OPSYS} == "SunOS" && (${OS_VERSION} == "5.9" || ${OS_VERSION} == "5.10")
LDFLAGS+=	-lrt
.endif

.if ${OPSYS} == "NetBSD"
LDFLAGS+=	-lrt
.endif

.if ${OPSYS} == "Darwin" && ${OPSYS_VERSION} < 100600
.  include "../../devel/macports-legacy-support/buildlink3.mk"
# posix_memalign is missing before 10.6
LDFLAGS+=	-lMacportsLegacySupport
.endif

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
