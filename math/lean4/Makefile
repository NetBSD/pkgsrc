# $NetBSD: Makefile,v 1.7 2026/08/03 15:03:26 wiz Exp $

DISTNAME=	lean4-4.32.2
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_GITHUB:=leanprover/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://lean-lang.org/
#HOMEPAGE=	https://github.com/leanprover/lean4/
COMMENT=	Programming language for theorem proving
LICENSE=	apache-2.0

DEPENDS+=	leantar-[0-9]*:../../math/leantar
DEPENDS+=	cadical>=3:../../math/cadical3

USE_LANGUAGES=	c c++
USE_TOOLS+=	bash:run gmake pkg-config

USE_CXX_FEATURES=	c++20

# needed for stage0 tools that are called during build and installation
MAKE_ENV+=	LD_LIBRARY_PATH=${WRKSRC}/${CMAKE_BUILD_DIR}/stage0/lib/lean:${WRKSRC}/${CMAKE_BUILD_DIR}/stage0/lib
INSTALL_ENV+=	LD_LIBRARY_PATH=${WRKSRC}/${CMAKE_BUILD_DIR}/stage0/lib/lean:${WRKSRC}/${CMAKE_BUILD_DIR}/stage0/lib

INSTALLATION_DIRS+=	share/lean4

CMAKE_CONFIGURE_ARGS+=	-DUSE_MIMALLOC=no
# stage0/stage1 options need to be passed explicitly
CMAKE_CONFIGURE_ARGS+=	-DSTAGE0_CMAKE_PREFIX_PATH=${BUILDLINK_DIR}
CMAKE_CONFIGURE_ARGS+=	-DSTAGE1_CMAKE_INSTALL_PREFIX=${PREFIX}
# don't install these binaries, they are dependencies
CMAKE_CONFIGURE_ARGS+=	-DSTAGE1_INSTALL_CADICAL=OFF
CMAKE_CONFIGURE_ARGS+=	-DSTAGE1_INSTALL_LEANTAR=OFF

# LDFLAGS from environment are ignored
CMAKE_CONFIGURE_ARGS+=	-DTOOLCHAIN_SHARED_LINKER_FLAGS=${LDFLAGS:Q}

LDFLAGS+=	${COMPILER_RPATH_FLAG}${PREFIX}/lib/lean

REPLACE_BASH+=	src/bin/leanmake
REPLACE_BASH+=	stage0/src/bin/leanmake

# avoid pkgsrc cwrapper cc in installed file
SUBST_CLASSES+=		cc
SUBST_FILES.cc+=	src/Leanc.lean
SUBST_FILES.cc+=	src/lake/Lake/Build/Common.lean
SUBST_SED.cc+=		-e "s,@LEANC_CC@,${CC},"
SUBST_SED.cc+=		-e "s!@LINKER_FLAGS@!\"${COMPILER_RPATH_FLAG}${PREFIX}/lib\", \"${COMPILER_RPATH_FLAG}${PREFIX}/lib/lean\"!"
SUBST_STAGE.cc=		pre-configure
SUBST_MESSAGE.cc=	Setting compiler path.

# CMakeLists.txt: "Only makefile generators are supported"
CMAKE_GENERATORS_INCOMPATIBLE=	ninja

post-install:
	${MV} ${DESTDIR}${PREFIX}/LICENSE* ${DESTDIR}${PREFIX}/share/lean4
	${CHMOD} a+x ${DESTDIR}${PREFIX}/lib/lean/*.so

.include "../../devel/cmake/build.mk"
.include "../../devel/libuv/buildlink3.mk"
BUILDLINK_API_DEPENDS.gmp+=	gmp>=5.0.5
.include "../../devel/gmp/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
