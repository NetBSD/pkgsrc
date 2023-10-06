# $NetBSD: Makefile,v 1.23 2023/10/06 19:15:19 adam Exp $

.include "../../lang/llvm/version.mk"

DISTNAME=	lld-${LLVM_VERSION}.src
PKGNAME=	${DISTNAME:S/.src//}
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://lld.llvm.org/
COMMENT=	The LLVM Linker
LICENSE=	apache-2.0

USE_CXX_FEATURES+=	c++14
USE_LANGUAGES=		c c++
GCC_REQD+=		7

CMAKE_ARGS+=	-DCMAKE_BUILD_TYPE=Release
CMAKE_ARGS+=	-DCMAKE_C_COMPILER=${CC:Q}
CMAKE_ARGS+=	-DCMAKE_CXX_COMPILER=${CXX:Q}

PYTHON_FOR_BUILD_ONLY=	yes

INSTALLATION_DIRS+=	libexec/lld

post-install:
	${LN} -sf ${PREFIX}/bin/lld ${DESTDIR}${PREFIX}/libexec/lld/ld

.include "options.mk"
.include "../../devel/cmake/build.mk"
.include "../../lang/llvm/buildlink3.mk"
.include "../../lang/libunwind/buildlink3.mk"
.include "../../lang/python/tool.mk"
.include "../../mk/atomic64.mk"
.include "../../mk/bsd.pkg.mk"
