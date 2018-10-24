# $NetBSD: Makefile,v 1.45 2018/10/24 21:12:59 maya Exp $

PKGNAME=		${DISTNAME:S/.src//:S/cfe/clang/}
PKGREVISION=		1
PYTHON_FOR_BUILD_ONLY=	yes

CMAKE_ARGS+=	-DCLANG_ENABLE_STATIC_ANALYZER=OFF

# There are some contrib utilities written in python here.
# We don't want to add a python runtime dependency for that.
CHECK_INTERPRETER_SKIP+=	share/clang/*

.include "../../lang/clang/Makefile.common"
