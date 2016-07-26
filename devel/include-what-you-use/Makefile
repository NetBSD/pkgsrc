# $NetBSD: Makefile,v 1.5 2016/07/26 12:47:24 wiz Exp $

DISTNAME=	include-what-you-use-0.6.src
PKGNAME=	${DISTNAME:.src=}
CATEGORIES=	devel
MASTER_SITES=	http://include-what-you-use.org/downloads/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://include-what-you-use.org/downloads/
COMMENT=	Analyze \#includes in C and C++ source files
#LICENSE=	# TODO: (see mk/license.mk)

WRKSRC=		${WRKDIR}/include-what-you-use
USE_CMAKE=	yes
CMAKE_ARGS=     -DIWYU_LLVM_ROOT_PATH:PATH=${BUILDLINK_PREFIX.clang}
USE_LANGUAGES=	c c++
GCC_REQD+=	4.8

REPLACE_PYTHON= *.py

.include "../../lang/clang/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
