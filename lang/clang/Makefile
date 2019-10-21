# $NetBSD: Makefile,v 1.51 2019/10/21 11:47:16 rjs Exp $

.include "Makefile.common"

PKGNAME=	${DISTNAME:S/.src//:S/cfe/clang/}
PKGREVISION=	1

CMAKE_ARGS+=	-DCLANG_ENABLE_STATIC_ANALYZER=OFF

PYTHON_FOR_BUILD_ONLY=	yes

# There are some contrib utilities written in python here.
# We don't want to add a python runtime dependency for that.
CHECK_INTERPRETER_SKIP+=	share/clang/*

.include "../../mk/bsd.pkg.mk"
