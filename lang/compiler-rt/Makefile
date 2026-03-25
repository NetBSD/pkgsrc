# $NetBSD: Makefile,v 1.29 2026/03/25 22:56:26 wiz Exp $

.include "../../lang/llvm/version.mk"

PKGNAME=	compiler-rt-${LLVM_VERSION}

CATEGORIES=	lang devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://compiler-rt.llvm.org/
COMMENT=	LLVM runtime libraries
LICENSE=	apache-2.0

NOT_FOR_PLATFORM=	NetBSD-[0-7].*-*

USE_CC_FEATURES=	c99
USE_CXX_FEATURES=	c++17
USE_LANGUAGES=		c c++
USE_TOOLS+=		ggrep
GCC_REQD+=		4.8
SSP_SUPPORTED=		no
# CMake Error: failed to create symbolic link '.../outline_atomic_cas1_1.S': File exists
MAKE_JOBS_SAFE=		no

CMAKE_CONFIGURE_ARGS+=	-DCMAKE_BUILD_TYPE=Release
CMAKE_CONFIGURE_ARGS+=	-DCOMPILER_RT_TEST_COMPILER=${PKG_CC:Q}
CMAKE_CONFIGURE_ARGS+=	-DCOMPILER_RT_OS_DIR:STRING=${OPSYS:tl}
CMAKE_CONFIGURE_ARGS+=	-DCOMPILER_RT_INSTALL_PATH:STRING=lib/clang/${LLVM_MAJOR_VERSION}
CMAKE_CONFIGURE_ARGS+=	-DLLVM_CONFIG_PATH=${LLVM_CONFIG_PATH:Q}
CMAKE_CONFIGURE_ARGS+=	-DCOMPILER_RT_ENABLE_IOS=OFF

.include "../../mk/bsd.prefs.mk"

# Not available to all platforms; see lib/tsan/rtl/tsan_platform_linux.cpp
# TODO: exclude more platforms
.if ${OPSYS} == "NetBSD" && ${MACHINE_ARCH} != "x86_64"
CMAKE_CONFIGURE_ARGS+=	-DCOMPILER_RT_BUILD_SANITIZERS=OFF
.endif

TEST_TARGET=	check-compiler-rt

GENERATE_PLIST+=	${FIND} ${DESTDIR}${PREFIX} \( -type f -o -type l \) -print | \
			${SED} 's,${DESTDIR}${PREFIX}/,,' | ${SORT} ;

PYTHON_FOR_BUILD_ONLY=	yes

.if ${OPSYS} == "Darwin"
post-install:
	cd ${DESTDIR}${PREFIX} && \
	${FIND} lib/clang/${LLVM_MAJOR_VERSION} -type f -name '*.dylib' \
		-exec install_name_tool -id ${PREFIX}/{} {} \;
.endif

.include "../../devel/cmake/build.mk"
.include "../../devel/googletest/buildlink3.mk"
.include "../../lang/llvm/buildlink3.mk"
.include "../../lang/python/tool.mk"
.include "../../mk/bsd.pkg.mk"
