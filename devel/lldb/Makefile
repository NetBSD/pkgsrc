# $NetBSD: Makefile,v 1.51 2024/05/29 16:32:15 adam Exp $

PKGREVISION= 1
.include "../../lang/llvm/version.mk"

DISTNAME=	lldb-${LLVM_VERSION}.src
PKGNAME=	${DISTNAME:S/.src//}
CATEGORIES=	devel lang

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://lldb.org/
COMMENT=	Next generation, high-performance debugger
LICENSE=	apache-2.0

DEPENDS+=	llvm-${PKGVERSION_NOREV}{,nb*}:../../lang/llvm
DEPENDS+=	clang-${PKGVERSION_NOREV}{,nb*}:../../lang/clang
DEPENDS+=	swig3>=3.0:../../devel/swig3
DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six

USE_CXX_FEATURES=	c++14
USE_LANGUAGES=		c c++
GCC_REQD+=		7
PY_PATCHPLIST=		yes

CMAKE_ARGS+=	-DLLVM_CONFIG=${LLVM_CONFIG_PATH:Q}
CMAKE_ARGS+=	-DCMAKE_BUILD_TYPE=Release
CMAKE_ARGS+=	-DCMAKE_C_COMPILER=${CC:Q}
CMAKE_ARGS+=	-DCMAKE_CXX_COMPILER=${CXX:Q}
CMAKE_ARGS+=	-DHAVE_CXX_ATOMICS64_WITHOUT_LIB=ON
CMAKE_ARGS+=	-DLLDB_CODESIGN_IDENTITY=""
CMAKE_ARGS+=	-DLLDB_USE_SYSTEM_SIX=ON
CMAKE_ARGS+=	-DPYTHON_HOME=${PREFIX}

CHECK_PORTABILITY_SKIP=	utils/buildit/build_llvm

LUA_VERSIONS_ACCEPTED=	53

REPLACE_PERL+=		*/*.pl

REPLACE_PYTHON+=	*.py
REPLACE_PYTHON+=	*/*.py
REPLACE_PYTHON+=	*/*/*.py
REPLACE_PYTHON+=	*/*/*/*.py
REPLACE_PYTHON+=	*/*/*/*/*.py
REPLACE_PYTHON+=	*/*/*/*/*/*.py
REPLACE_PYTHON+=	*/*/*/*/*/*/*.py
REPLACE_PYTHON+=	*/*/*/*/*/*/*/*.py

TEST_TARGET=		check-lldb
#TEST_TARGET=		check-lldb-unit # doesn't work in standalone build
#TEST_TARGET=		check-lldb-single # check-lldb -j1
#TEST_TARGET=		check-lldb-expr # unknown
TEST_ENV+=		LD_LIBRARY_PATH=${WRKDIR}/build/lib

.include "../../mk/bsd.prefs.mk"

PLIST_SUBST+=	LLVM_MAJOR_VERSION=${LLVM_MAJOR_VERSION}

.include "options.mk"

.if ${OPSYS} == "NetBSD"
.  if ${OPSYS_VERSION} < 99922
# lacks ptrace(2) PT_STOP
PKG_FAIL_REASON+=	"Only NetBSD >= 9.99.22 provides ptrace(2) PT_STOP"
.  endif
.endif

# Not yet ported, so avoid wasting time trying...
NOT_FOR_PLATFORM+=	NetBSD-*-powerpc

.include "../../devel/cmake/build.mk"
#.include "../../devel/googletest/buildlink3.mk" # check-lldb-unit
.include "../../devel/editline/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../lang/clang/buildlink3.mk"
.include "../../lang/llvm/buildlink3.mk"
.include "../../lang/lua/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../lang/python/tool.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/atomic64.mk"
# TODO: sync the readline option with other llvm packages
.include "../../mk/readline.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
