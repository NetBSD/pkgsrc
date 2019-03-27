# $NetBSD: Makefile,v 1.48 2019/03/27 06:24:22 adam Exp $

.include "../../lang/clang/Makefile.common"

PKGNAME=		${DISTNAME:S/.src//:S/cfe/clang/}
PKGREVISION=		1
PYTHON_FOR_BUILD_ONLY=	yes

CMAKE_ARGS+=	-DCLANG_ENABLE_STATIC_ANALYZER=OFF

# There are some contrib utilities written in python here.
# We don't want to add a python runtime dependency for that.
CHECK_INTERPRETER_SKIP+=	share/clang/*

.include "../../mk/bsd.pkg.mk"
