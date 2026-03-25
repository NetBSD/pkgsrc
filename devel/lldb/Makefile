# $NetBSD: Makefile,v 1.63 2026/03/25 22:56:25 wiz Exp $

.include "../../lang/llvm/version.mk"

PKGNAME=	lldb-${LLVM_VERSION}
CATEGORIES=	devel lang

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://lldb.org/
COMMENT=	Next generation, high-performance debugger
LICENSE=	apache-2.0

DEPENDS+=	llvm-${PKGVERSION_NOREV}{,nb*}:../../lang/llvm
DEPENDS+=	clang-${PKGVERSION_NOREV}{,nb*}:../../lang/clang
#DEPENDS+=	swig3>=3.0:../../devel/swig3
DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six

USE_CXX_FEATURES=	c++17
USE_LANGUAGES=		c c++
GCC_REQD+=		7
PY_PATCHPLIST=		yes

# FIXME: currently build fails when libcxx is also installed.
CMAKE_CONFIGURE_ARGS+=	-DLLVM_CONFIG=${LLVM_CONFIG_PATH:Q}
#CMAKE_CONFIGURE_ARGS+=	-DLLVM_ENABLE_LIBCXX=ON
CMAKE_CONFIGURE_ARGS+=	-DCMAKE_BUILD_TYPE=Release
CMAKE_CONFIGURE_ARGS+=	-DCMAKE_C_COMPILER=${CC:Q}
CMAKE_CONFIGURE_ARGS+=	-DCMAKE_CXX_COMPILER=${CXX:Q}
CMAKE_CONFIGURE_ARGS+=	-DHAVE_CXX_ATOMICS64_WITHOUT_LIB=ON
CMAKE_CONFIGURE_ARGS+=	-DLLDB_CODESIGN_IDENTITY=""
CMAKE_CONFIGURE_ARGS+=	-DPYTHON_HOME=${PREFIX}

CHECK_PORTABILITY_SKIP=	utils/buildit/build_llvm

LUA_VERSIONS_INCOMPATIBLE=	51 52
PLIST_SUBST+=			LUA_VERSION=${LUA_VERSION:R}

REPLACE_PERL+=		scripts/disasm-gdb-remote.pl

REPLACE_PYTHON+=	bindings/python/get-python-config.py
REPLACE_PYTHON+=	bindings/python/lldb-python
REPLACE_PYTHON+=	scripts/analyze-project-deps.py
REPLACE_PYTHON+=	scripts/generate-sbapi-dwarf-enum.py
REPLACE_PYTHON+=	scripts/reproducer-replay.py
REPLACE_PYTHON+=	scripts/verify_api.py
REPLACE_PYTHON+=	utils/lldb-repro/lldb-repro.py
REPLACE_PYTHON+=	utils/lui/lui.py
REPLACE_PYTHON+=	utils/lui/sandbox.py

TEST_TARGET=		check-lldb
#TEST_TARGET=		check-lldb-unit # doesn't work in standalone build
#TEST_TARGET=		check-lldb-single # check-lldb -j1
#TEST_TARGET=		check-lldb-expr # unknown
TEST_ENV+=		LD_LIBRARY_PATH=${WRKDIR}/build/lib

.include "../../mk/bsd.prefs.mk"

.include "options.mk"

.if ${OPSYS} == "NetBSD"
.  if ${OPSYS_VERSION} < 99922
# lacks ptrace(2) PT_STOP
PKG_FAIL_REASON+=	"Only NetBSD >= 9.99.22 provides ptrace(2) PT_STOP"
.  endif
.endif

# Not yet ported, so avoid wasting time trying...
# See: source/Plugins/Process/NetBSD
NOT_FOR_PLATFORM+=	NetBSD-*-aarch64 NetBSD-*-powerpc

.include "../../devel/cmake/build.mk"
#.include "../../devel/googletest/buildlink3.mk" # check-lldb-unit
.include "../../devel/editline/buildlink3.mk"
.include "../../devel/swig4/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../lang/clang/buildlink3.mk"
#.include "../../lang/libcxx/buildlink3.mk"
.include "../../lang/llvm/buildlink3.mk"
.include "../../lang/lua/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../lang/python/tool.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/atomic64.mk"
.include "../../mk/bsd.pkg.mk"
