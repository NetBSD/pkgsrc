# $NetBSD: Makefile,v 1.53 2019/11/03 11:55:53 kamil Exp $

.include "Makefile.common"

PKGNAME=	${DISTNAME:S/.src//:S/cfe/clang/}
PKGREVISION=	3

CMAKE_ARGS+=	-DCLANG_ENABLE_STATIC_ANALYZER=OFF

PYTHON_FOR_BUILD_ONLY=	yes

# There are some contrib utilities written in python here.
# We don't want to add a python runtime dependency for that.
CHECK_INTERPRETER_SKIP+=	share/clang/*

.include "../../mk/bsd.pkg.mk"
