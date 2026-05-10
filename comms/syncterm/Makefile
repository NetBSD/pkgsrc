# $NetBSD: Makefile,v 1.17 2026/05/10 06:06:05 vins Exp $

DISTNAME=	syncterm-1.8-src
PKGNAME=	${DISTNAME:S/-src//}
PKGREVISION=	1
CATEGORIES=	comms
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=syncterm/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	vins@NetBSD.org
HOMEPAGE=	http://syncterm.bbsdev.net/
COMMENT=	ANSI-BBS terminal designed to connect to remote BBSs
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
BUILD_DIRS=	src/syncterm

USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake gzip perl:build
USE_TOOLS+=	pkg-config sed

USE_CC_FEATURES=	c11

PTHREAD_AUTO_VARS=	yes
BUILDLINK_TRANSFORM+=	rm:-lpthread

CFLAGS+=	-DUSE_SNPRINTF			  # avoid redefinition
CFLAGS.SunOS+=	-DNEEDS_CFMAKERAW -DNEEDS_FORKPTY # missing on SunOS

.include "../../mk/endian.mk"
.if ${MACHINE_ENDIAN} == "big"
CFLAGS+=	-D__BIG_ENDIAN__		  # build on any big-endian arch
.endif

LDFLAGS+=	-lrt				  # shm_open()

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
SUBST_CLASSES+=		ints
SUBST_MESSAGE.ints=	SunOS stdint(3) doesn't provide `u_int*' typedefs
SUBST_STAGE.ints=	pre-configure
SUBST_FILES.ints+=	src/xpdev/xpevent.h
SUBST_FILES.ints+=	src/xpdev/sockwrap.h
SUBST_SED.ints=		-e 's|u_int|uint|g'
.endif

MAKE_FILE=	GNUmakefile

MAKE_ENV+=	CFLAGS=${CFLAGS:Q}
MAKE_ENV+=	LDFLAGS=${LDFLAGS:Q}

MAKE_FLAGS+=	RELEASE=1					\
		SRC_ROOT=${WRKSRC}/src				\
		PREFIX=${PREFIX}				\
		MANPREFIX=${PREFIX}/${PKGMANDIR:S,man$,,g}	\
		SYSTEM_LIST_DIR=${PKG_SYSCONFDIR}		\
		INSTALL_EXE=${INSTALL:Q}			\
		WITHOUT_CRYPTLIB=1				\
		QUIET=

.include "options.mk"

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/dlopen.buildlink3.mk"
BUILDLINK_TRANSFORM+=   opt:-ldl:${BUILDLINK_LDADD.dl:Q}
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
