# $NetBSD: Makefile,v 1.58 2020/07/02 10:45:38 wiz Exp $

.include "Makefile.common"

PKGNAME=	${DISTNAME:S/.src//}
PKGREVISION=	4

PYTHON_FOR_BUILD_ONLY=	yes

USE_TOOLS+=	perl:run

# There are some contrib utilities written in python here.
# We don't want to add a python runtime dependency for that.
CHECK_INTERPRETER_SKIP+=	share/clang/*

.include "../../mk/bsd.pkg.mk"
