# $NetBSD: Makefile,v 1.50 2019/06/02 08:39:28 adam Exp $

.include "Makefile.common"

PKGNAME=	${DISTNAME:S/.src//:S/cfe/clang/}

CMAKE_ARGS+=	-DCLANG_ENABLE_STATIC_ANALYZER=OFF

PYTHON_FOR_BUILD_ONLY=	yes

# There are some contrib utilities written in python here.
# We don't want to add a python runtime dependency for that.
CHECK_INTERPRETER_SKIP+=	share/clang/*

.include "../../mk/bsd.pkg.mk"
