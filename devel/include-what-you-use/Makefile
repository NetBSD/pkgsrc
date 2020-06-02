# $NetBSD: Makefile,v 1.21 2020/06/02 08:23:36 adam Exp $

DISTNAME=	include-what-you-use-0.14.src
PKGNAME=	${DISTNAME:S/.src//1}
PKGREVISION=	1
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

REPLACE_PYTHON=	*.py

.include "../../lang/clang/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
