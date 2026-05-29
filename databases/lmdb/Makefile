# $NetBSD: Makefile,v 1.28 2026/05/29 08:57:50 wiz Exp $

.include "../../databases/openldap/Makefile.version"

# get the version from libraries/liblmdb/lmdb.h
PKGNAME=	lmdb-0.9.35
PKGREVISION=	1
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

INSTALLATION_DIRS+=	lib/pkgconfig
INSTALLATION_DIRS+=	${PKGMANDIR}/man1

CHECK_PORTABILITY_SKIP=	configure
TEST_TARGET=		test

SUBST_CLASSES+=		pc
SUBST_VARS.pc+=		PREFIX PKGVERSION
SUBST_FILES.pc+=	lmdb.pc
SUBST_STAGE.pc=		pre-configure
SUBST_MESSAGE.pc=	Fixing pkg-config file.

post-extract:
	${CP} ${FILESDIR}/lmdb.pc ${WRKSRC}

post-install:
	${INSTALL_DATA} ${WRKSRC}/lmdb.pc ${DESTDIR}${PREFIX}/lib/pkgconfig

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
