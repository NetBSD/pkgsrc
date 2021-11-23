# $NetBSD: Makefile,v 1.26 2021/11/23 20:55:42 wiz Exp $

DISTNAME=	include-what-you-use-0.16.src
PKGNAME=	${DISTNAME:S/.src//1}
CATEGORIES=	devel
MASTER_SITES=	https://include-what-you-use.org/downloads/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://include-what-you-use.org/
COMMENT=	Analyze \#includes in C and C++ source files
LICENSE=	modified-bsd

WRKSRC=		${WRKDIR}/include-what-you-use
USE_CMAKE=	yes
USE_LANGUAGES=	c c++14

GCC_REQD+=	5

CMAKE_ARGS=	-DIWYU_LLVM_ROOT_PATH:PATH=${BUILDLINK_PREFIX.clang}

BROKEN=		"Needs to be updated for llvm-13.0.0"
# https://github.com/include-what-you-use/include-what-you-use/issues/974

REPLACE_PYTHON=	*.py

.include "../../lang/clang/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
