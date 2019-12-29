# $NetBSD: Makefile,v 1.54 2019/12/29 15:31:22 adam Exp $

.include "Makefile.common"

PKGNAME=	${DISTNAME:S/.src//}

CMAKE_ARGS+=	-DCLANG_ENABLE_STATIC_ANALYZER=OFF

PYTHON_FOR_BUILD_ONLY=	yes

# There are some contrib utilities written in python here.
# We don't want to add a python runtime dependency for that.
CHECK_INTERPRETER_SKIP+=	share/clang/*

.include "../../mk/bsd.pkg.mk"
