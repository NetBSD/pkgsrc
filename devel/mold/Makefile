# $NetBSD: Makefile,v 1.18 2022/07/02 21:22:44 fcambus Exp $

DISTNAME=	mold-1.3.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=rui314/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	fcambus@NetBSD.org
HOMEPAGE=	https://github.com/rui314/mold/
COMMENT=	High performance drop-in replacement for existing Unix linkers
LICENSE=	gnu-agpl-v3

USE_TOOLS+=	gmake
USE_LANGUAGES=	c c++20

# Use <stdlib.h> on systems where <alloca.h> doesn't exist
.if !exists(/usr/include/alloca.h)
SUBST_CLASSES+=		alloca
SUBST_STAGE.alloca=	post-configure
SUBST_FILES.alloca=	elf/mold-wrapper.c
SUBST_SED.alloca=	-e 's|<alloca.h>|<stdlib.h>|g'
.endif

MAKE_FLAGS+=	CFLAGS="${CFLAGS}"
MAKE_FLAGS+=	CXXFLAGS="${CXXFLAGS}"
MAKE_FLAGS+=	PREFIX="${PREFIX}"
MAKE_FLAGS+=	MANDIR="${PREFIX}/${PKGMANDIR}"
MAKE_FLAGS+=	SYSTEM_MIMALLOC=1 SYSTEM_TBB=1

# This package uses a lot of C++20 features. GCC 10 is the oldest GCC that can
# build it.
GCC_REQD+=	10

# Handle linker flags for dlopen and pthread automatically.
DL_AUTO_VARS=		yes
PTHREAD_AUTO_VARS=	yes

PYTHON_FOR_BUILD_ONLY=	yes

pre-configure:
	# install phase uses python3 command
	[ -h "${BUILDLINK_DIR}/bin/python3" ] || ${LN} -s ${PYTHONBIN} "${BUILDLINK_DIR}/bin/python3"

.include "../../devel/mimalloc/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../parallel/threadingbuildingblocks/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
