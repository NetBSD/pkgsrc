# $NetBSD: Makefile,v 1.36 2024/05/11 15:25:33 wiz Exp $

DISTNAME=	pygit2-1.14.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pygit2/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/libgit2/pygit2
COMMENT=	Python bindings to libgit2
LICENSE=	gnu-gpl-v2

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-cffi>=1.9.1:../../devel/py-cffi
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov

# error: 'for' loop initial declarations are only allowed in C99 mode
FORCE_C_STD=	c99

PYTHON_VERSIONS_INCOMPATIBLE=	27 38

BROKEN=		"Waiting for release working with libgit2 1.8."

.include "../../devel/libgit2/buildlink3.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
