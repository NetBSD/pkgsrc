# $NetBSD: Makefile,v 1.38 2023/11/08 13:18:48 wiz Exp $

DISTNAME=	include-what-you-use-0.20
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=include-what-you-use/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://include-what-you-use.org/
COMMENT=	Analyze \#includes in C and C++ source files
LICENSE=	modified-bsd

USE_CXX_FEATURES+=	c++17
USE_LANGUAGES=		c c++

CMAKE_ARGS=	-DIWYU_LLVM_ROOT_PATH:PATH=${BUILDLINK_PREFIX.clang}

REPLACE_PYTHON=	*.py

.include "../../devel/cmake/build.mk"
.include "../../lang/clang/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
