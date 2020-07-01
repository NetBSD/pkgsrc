# $NetBSD: Makefile,v 1.57 2020/07/01 14:46:37 adam Exp $

.include "Makefile.common"

PKGNAME=	${DISTNAME:S/.src//}
PKGREVISION=	3

PYTHON_FOR_BUILD_ONLY=	yes

# There are some contrib utilities written in python here.
# We don't want to add a python runtime dependency for that.
CHECK_INTERPRETER_SKIP+=	share/clang/*

.include "../../mk/bsd.pkg.mk"
