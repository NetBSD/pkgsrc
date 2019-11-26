# $NetBSD: Makefile,v 1.18 2019/11/26 18:34:31 nia Exp $

DISTNAME=	include-what-you-use-0.13.src
PKGNAME=	${DISTNAME:S/.src//1}
CATEGORIES=	devel
MASTER_SITES=	https://include-what-you-use.org/downloads/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://include-what-you-use.org/
COMMENT=	Analyze \#includes in C and C++ source files
LICENSE=	modified-bsd

WRKSRC=		${WRKDIR}/include-what-you-use
USE_CMAKE=	yes
USE_LANGUAGES=	c c++

GCC_REQD+=	4.8

CMAKE_ARGS=	-DIWYU_LLVM_ROOT_PATH:PATH=${BUILDLINK_PREFIX.clang}

REPLACE_PYTHON=	*.py

.include "../../lang/clang/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
