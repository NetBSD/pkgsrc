# $NetBSD: Makefile,v 1.59 2020/07/26 19:20:13 adam Exp $

.include "Makefile.common"

PKGNAME=	${DISTNAME:S/.src//}

PYTHON_FOR_BUILD_ONLY=	yes

USE_TOOLS+=	perl:run

# There are some contrib utilities written in python here.
# We don't want to add a python runtime dependency for that.
CHECK_INTERPRETER_SKIP+=	share/clang/*

.include "../../mk/bsd.pkg.mk"
