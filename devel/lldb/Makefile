# $NetBSD: Makefile,v 1.23 2019/10/19 14:01:37 adam Exp $

DISTNAME=	lldb-9.0.0.src
PKGNAME=	${DISTNAME:S/.src//}
CATEGORIES=	lang devel
MASTER_SITES=	http://releases.llvm.org/${PKGVERSION_NOREV}/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://lldb.org/
COMMENT=	Next generation, high-performance debugger
LICENSE=	modified-bsd

DEPENDS+=	llvm-${PKGVERSION_NOREV}{,nb*}:../../lang/llvm
DEPENDS+=	clang-${PKGVERSION_NOREV}{,nb*}:../../lang/clang
DEPENDS+=	swig3>=3.0:../../devel/swig3
DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six

CONFIGURE_DIRS=		${WRKDIR}/build
CMAKE_ARG_PATH=		${WRKSRC}

USE_CMAKE=		yes
USE_LANGUAGES=		c c++11
GCC_REQD+=		4.8
PY_PATCHPLIST=		yes

CMAKE_ARGS+=	-DLLVM_CONFIG=${LLVM_CONFIG_PATH}
CMAKE_ARGS+=	-DCMAKE_BUILD_TYPE=Release
CMAKE_ARGS+=	-DCMAKE_C_COMPILER=${CC:Q}
CMAKE_ARGS+=	-DCMAKE_CXX_COMPILER=${CXX:Q}
CMAKE_ARGS+=	-DHAVE_CXX_ATOMICS64_WITHOUT_LIB=ON
CMAKE_ARGS+=	-DLLDB_CODESIGN_IDENTITY=""
CMAKE_ARGS+=	-DLLDB_USE_SYSTEM_SIX:BOOL=TRUE

CHECK_PORTABILITY_SKIP=	utils/buildit/build_llvm

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

PLIST_VARS+=	posix
.if ${OPSYS} != "Darwin"
PLIST.posix=	yes
.endif

.if ${OPSYS} == "NetBSD"
.  if exists(/usr/include/panel.h)
CMAKE_ARGS+=	-DLLDB_DISABLE_CURSES:BOOL=FALSE
.  else
CMAKE_ARGS+=	-DLLDB_DISABLE_CURSES:BOOL=TRUE
.  endif
.endif

post-extract:
	${MKDIR} ${WRKDIR}/build

#.include "../../devel/googletest/buildlink3.mk" # check-lldb-unit
.include "../../devel/libatomic_ops/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../lang/clang/buildlink3.mk"
.include "../../lang/llvm/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../lang/python/tool.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/readline.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
