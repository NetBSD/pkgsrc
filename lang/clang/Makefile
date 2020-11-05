# $NetBSD: Makefile,v 1.61 2020/11/05 09:06:56 ryoon Exp $

PKGREVISION= 2
.include "Makefile.common"

PKGNAME=	${DISTNAME:S/.src//}

PYTHON_FOR_BUILD_ONLY=	yes

USE_TOOLS+=	perl:run

# There are some contrib utilities written in python here.
# We don't want to add a python runtime dependency for that.
CHECK_INTERPRETER_SKIP+=	share/clang/*

.include "../../mk/bsd.pkg.mk"
