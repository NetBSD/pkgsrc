# $NetBSD: Makefile,v 1.55 2020/05/07 20:21:41 rillig Exp $

.include "Makefile.common"

PKGNAME=	${DISTNAME:S/.src//}
PKGREVISION=	1

CMAKE_ARGS+=	-DCLANG_ENABLE_STATIC_ANALYZER=OFF

PYTHON_FOR_BUILD_ONLY=	yes

# There are some contrib utilities written in python here.
# We don't want to add a python runtime dependency for that.
CHECK_INTERPRETER_SKIP+=	share/clang/*

.include "../../mk/bsd.pkg.mk"
