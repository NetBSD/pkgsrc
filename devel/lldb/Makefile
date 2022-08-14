# $NetBSD: Makefile,v 1.40 2022/08/14 15:00:18 tnn Exp $

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

CONFIGURE_DIRS=		build
CMAKE_ARG_PATH=		${WRKSRC}

USE_CMAKE=		yes
USE_LANGUAGES=		c c++14
GCC_REQD+=		7
PY_PATCHPLIST=		yes

CMAKE_ARGS+=	-DLLVM_CONFIG=${LLVM_CONFIG_PATH}
CMAKE_ARGS+=	-DCMAKE_BUILD_TYPE=Release
CMAKE_ARGS+=	-DCMAKE_C_COMPILER=${CC:Q}
CMAKE_ARGS+=	-DCMAKE_CXX_COMPILER=${CXX:Q}
CMAKE_ARGS+=	-DHAVE_CXX_ATOMICS64_WITHOUT_LIB=ON
CMAKE_ARGS+=	-DLLDB_CODESIGN_IDENTITY=""
CMAKE_ARGS+=	-DLLDB_USE_SYSTEM_SIX=ON
CMAKE_ARGS+=	-DPYTHON_HOME=${PREFIX}

CHECK_PORTABILITY_SKIP=	utils/buildit/build_llvm

LUA_VERSIONS_ACCEPTED=	53

REPLACE_PERL+=		*.pl
REPLACE_PERL+=		*/*.pl
REPLACE_PERL+=		*/*/*.pl
REPLACE_PERL+=		*/*/*/*.pl
REPLACE_PERL+=		*/*/*/*/*.pl
REPLACE_PERL+=		*/*/*/*/*/*.pl
REPLACE_PERL+=		scripts/sed-sources

REPLACE_PYTHON+=	*.py
REPLACE_PYTHON+=	*/*.py
REPLACE_PYTHON+=	*/*/*.py
REPLACE_PYTHON+=	*/*/*/*.py
REPLACE_PYTHON+=	*/*/*/*/*.py
REPLACE_PYTHON+=	*/*/*/*/*/*.py
REPLACE_PYTHON+=	*/*/*/*/*/*/*.py
REPLACE_PYTHON+=	*/*/*/*/*/*/*/*.py
REPLACE_PYTHON+=	scripts/shush

TEST_TARGET=		check-lldb
#TEST_TARGET=		check-lldb-unit # doesn't work in standalone build
#TEST_TARGET=		check-lldb-single # check-lldb -j1
#TEST_TARGET=		check-lldb-expr # unknown
TEST_ENV+=		LD_LIBRARY_PATH=${WRKDIR}/build/lib

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
.  if exists(/usr/include/panel.h)
CMAKE_ARGS+=	-DLLDB_DISABLE_CURSES:BOOL=FALSE
.  else
CMAKE_ARGS+=	-DLLDB_DISABLE_CURSES:BOOL=TRUE
.  endif

.  if ${OPSYS_VERSION} < 99922
# lacks ptrace(2) PT_STOP
NOT_FOR_PLATFORM+=	NetBSD-*-*
.  endif
.endif

post-extract:
	${MKDIR} ${WRKSRC}/build

#.include "../../devel/googletest/buildlink3.mk" # check-lldb-unit
.include "../../devel/libatomic_ops/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../lang/clang/buildlink3.mk"
.include "../../lang/llvm/buildlink3.mk"
.include "../../lang/lua/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../lang/python/tool.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/readline.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
