# $NetBSD: Makefile,v 1.56 2020/06/02 08:22:45 adam Exp $

.include "Makefile.common"

PKGNAME=	${DISTNAME:S/.src//}
PKGREVISION=	2

CMAKE_ARGS+=	-DCLANG_ENABLE_STATIC_ANALYZER=OFF

PYTHON_FOR_BUILD_ONLY=	yes

# There are some contrib utilities written in python here.
# We don't want to add a python runtime dependency for that.
CHECK_INTERPRETER_SKIP+=	share/clang/*

.include "../../mk/bsd.pkg.mk"
