# $NetBSD: Makefile,v 1.7 2023/01/24 14:32:20 ryoon Exp $

DISTNAME=	pyrtl-${PKGVERSION_NOREV}
PKGNAME=	${PYPKGPREFIX}-PyRTL-0.10.2
CATEGORIES=	cad python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyrtl/}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://ucsbarchlab.github.io/PyRTL/
COMMENT=	Register-transfer-level hardware design and simulation
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six

# 'make test' fails with 2 arithmetic FAILs.
TEST_DEPENDS+=	${PYPKGPREFIX}-tox-[0-9]*:../../devel/py-tox
TEST_DEPENDS+=	${PYPKGPREFIX}-nose-[0-9]*:../../devel/py-nose

USE_LANGUAGES=	c # for test

EGG_NAME=	${DISTNAME:tl}

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
