# $NetBSD: Makefile,v 1.5 2018/12/09 20:04:40 adam Exp $

DISTNAME=	compiler-rt-7.0.0.src
PKGNAME=	${DISTNAME:S/.src//}
CATEGORIES=	lang devel
MASTER_SITES=	http://llvm.org/releases/${PKGVERSION_NOREV}/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://compiler-rt.llvm.org/
COMMENT=	LLVM runtime libraries
LICENSE=	modified-bsd OR mit

NOT_FOR_PLATFORM=	NetBSD-[0-7].*-*

USE_CMAKE=	yes
USE_LANGUAGES=	c99 c++11
USE_TOOLS+=	ggrep
GCC_REQD+=	4.8
SSP_SUPPORTED=	no

CONFIGURE_DIRS=	${WRKDIR}/build
CMAKE_ARG_PATH=	${WRKSRC}

OS_DIR.SunOS-5.11=	solaris2.11
OS_DIR=		${OS_DIR.${OPSYS}-${OS_VERSION}}

CMAKE_ARGS+=	-DCMAKE_BUILD_TYPE=Release
CMAKE_ARGS+=	-DCMAKE_C_COMPILER=${CC:Q}
CMAKE_ARGS+=	-DCMAKE_CXX_COMPILER=${CXX:Q}
CMAKE_ARGS+=	-DCOMPILER_RT_TEST_COMPILER=${PKG_CC:Q}
CMAKE_ARGS+=	-DCOMPILER_RT_OS_DIR:STRING=${OS_DIR}
CMAKE_ARGS+=	-DCOMPILER_RT_INSTALL_PATH:STRING=lib/clang/${PKGVERSION_NOREV}
CMAKE_ARGS+=	-DLLVM_CONFIG_PATH=${LLVM_CONFIG_PATH:Q}
CMAKE_ARGS+=	-DCOMPILER_RT_ENABLE_IOS=OFF

PLIST_SUBST+=	COMPILER_RT_OS_DIR=${OS_DIR}

TEST_TARGET=	check-compiler-rt

PYTHON_FOR_BUILD_ONLY=	yes

post-extract:
	${MKDIR} ${WRKDIR}/build

.include "../../devel/googletest/buildlink3.mk"
.include "../../lang/llvm/buildlink3.mk"
.include "../../lang/python/tool.mk"
.include "../../mk/bsd.pkg.mk"
