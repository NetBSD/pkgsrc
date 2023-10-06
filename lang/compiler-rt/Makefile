# $NetBSD: Makefile,v 1.22 2023/10/06 19:15:20 adam Exp $

.include "../../lang/llvm/version.mk"

DISTNAME=	compiler-rt-${LLVM_VERSION}.src
PKGNAME=	${DISTNAME:S/.src//}
CATEGORIES=	lang devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://compiler-rt.llvm.org/
COMMENT=	LLVM runtime libraries
LICENSE=	apache-2.0

NOT_FOR_PLATFORM=	NetBSD-[0-7].*-*

USE_CXX_FEATURES+=	c++14
USE_LANGUAGES=		c99 c++
USE_TOOLS+=		ggrep
GCC_REQD+=		4.8
SSP_SUPPORTED=		no

CMAKE_ARGS+=	-DCMAKE_BUILD_TYPE=Release
CMAKE_ARGS+=	-DCOMPILER_RT_TEST_COMPILER=${PKG_CC:Q}
CMAKE_ARGS+=	-DCOMPILER_RT_OS_DIR:STRING=${OPSYS:tl}
CMAKE_ARGS+=	-DCOMPILER_RT_INSTALL_PATH:STRING=lib/clang/${PKGVERSION_NOREV}
CMAKE_ARGS+=	-DLLVM_CONFIG_PATH=${LLVM_CONFIG_PATH:Q}
CMAKE_ARGS+=	-DCOMPILER_RT_ENABLE_IOS=OFF

TEST_TARGET=	check-compiler-rt

GENERATE_PLIST+=	${FIND} ${DESTDIR}${PREFIX} \( -type f -o -type l \) -print | \
			${SED} 's,${DESTDIR}${PREFIX}/,,' | ${SORT} ;

PYTHON_FOR_BUILD_ONLY=	yes

post-install:
	cd ${DESTDIR}${PREFIX} && \
	${FIND} lib/clang/${PKGVERSION_NOREV} -type f -name '*.dylib' \
		-exec install_name_tool -id ${PREFIX}/{} {} \;

.include "../../devel/cmake/build.mk"
.include "../../devel/googletest/buildlink3.mk"
.include "../../lang/llvm/buildlink3.mk"
.include "../../lang/python/tool.mk"
.include "../../mk/bsd.pkg.mk"
