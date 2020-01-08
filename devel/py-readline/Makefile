# $NetBSD: Makefile,v 1.35 2020/01/08 13:44:41 joerg Exp $

PKGNAME=	${PYPKGPREFIX}-readline-${PY_DISTVERSION}
CATEGORIES=	devel misc python

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://docs.python.org/3/library/readline.html
COMMENT=	Line editing support for Python

USE_GCC_RUNTIME=	yes

PYDISTUTILSPKG=		yes
PY_SETUP_SUBST+=	RLPREFIX=${BUILDLINK_PREFIX.readline}
PY_SETUP_SUBST+=	RLRTPREFIX=${BUILDLINK_PREFIX.readline}
PYSETUPINSTALLARGS+=	--install-lib ${PREFIX}/${PYLIB}/lib-dynload

.include "../../devel/readline/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../lang/python/srcdist.mk"
.include "../../mk/bsd.pkg.mk"
