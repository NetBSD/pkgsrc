# $NetBSD: Makefile,v 1.1 2015/12/30 16:16:13 bsiegert Exp $

DISTNAME=	include-what-you-use-0.5.src
PKGNAME=	${DISTNAME:.src=}
CATEGORIES=	devel
MASTER_SITES=	http://include-what-you-use.org/downloads/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://include-what-you-use.org/downloads/
COMMENT=	Analyze \#includes in C and C++ source files
#LICENSE=	# TODO: (see mk/license.mk)

WRKSRC=		${WRKDIR}/include-what-you-use
USE_CMAKE=	yes
CMAKE_ARGS=     -DIWYU_LLVM_ROOT_PATH=${BUILDLINK_DIR}
USE_LANGUAGES=	c c++
GCC_REQD=	4.8

USE_TOOLS=	python:run
REPLACE_PYTHON= iwyu_tool.py fix_includes.py

.include "../../lang/clang/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
