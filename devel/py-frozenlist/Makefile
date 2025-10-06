# $NetBSD: Makefile,v 1.15 2025/10/06 08:47:23 adam Exp $

DISTNAME=	frozenlist-1.8.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=f/frozenlist/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/aio-libs/frozenlist
COMMENT=	List-like structure which implements collections.abc.MutableSequence
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-cython-[0-9]*:../../devel/py-cython
TOOL_DEPENDS+=	${PYPKGPREFIX}-expandvars-[0-9]*:../../misc/py-expandvars
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov

USE_LANGUAGES=	c++

PYTHON_VERSIONS_INCOMPATIBLE=	39 310

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
