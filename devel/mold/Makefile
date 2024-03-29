# $NetBSD: Makefile,v 1.38 2023/11/16 20:42:17 fcambus Exp $

DISTNAME=	mold-2.3.3
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=rui314/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/rui314/mold/
COMMENT=	High performance drop-in replacement for existing Unix linkers
LICENSE=	mit

USE_LANGUAGES=	c c++20

USE_CMAKE=	yes

CMAKE_ARGS+=	-DMOLD_USE_SYSTEM_MIMALLOC=ON -DMOLD_USE_SYSTEM_TBB=ON

# Use <stdlib.h> on systems where <alloca.h> doesn't exist
.if !exists(/usr/include/alloca.h)
SUBST_CLASSES+=		alloca
SUBST_STAGE.alloca=	post-configure
SUBST_FILES.alloca=	elf/mold-wrapper.c
SUBST_SED.alloca=	-e 's|<alloca.h>|<stdlib.h>|g'
.endif

# This package uses a lot of C++20 features. GCC 10 is the oldest GCC that can
# build it.
USE_CXX_FEATURES+=	c++20

# Handle linker flags for dlopen and pthread automatically.
DL_AUTO_VARS=		yes
PTHREAD_AUTO_VARS=	yes

.include "../../archivers/zstd/buildlink3.mk"
.include "../../devel/mimalloc/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../parallel/threadingbuildingblocks/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
