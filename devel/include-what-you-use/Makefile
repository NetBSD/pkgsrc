# $NetBSD: Makefile,v 1.12 2017/12/13 17:51:45 wiz Exp $

DISTNAME=	include-what-you-use-0.8.src
PKGNAME=	${DISTNAME:.src=}
CATEGORIES=	devel
MASTER_SITES=	https://include-what-you-use.org/downloads/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://include-what-you-use.org/
COMMENT=	Analyze \#includes in C and C++ source files
LICENSE=	modified-bsd

WRKSRC=		${WRKDIR}/include-what-you-use
USE_CMAKE=	yes
USE_LANGUAGES=	c c++
CMAKE_ARGS=	-DIWYU_LLVM_ROOT_PATH:PATH=${BUILDLINK_PREFIX.clang}
GCC_REQD+=	4.8

REPLACE_PYTHON=	*.py
# https://github.com/include-what-you-use/include-what-you-use/issues/462
BROKEN=		Not ported to llvm 5.

.include "../../lang/clang/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
