# $NetBSD: Makefile,v 1.10 2024/09/18 06:23:15 wiz Exp $

DISTNAME=	pyrtl-${PKGVERSION_NOREV}
PKGNAME=	${PYPKGPREFIX}-PyRTL-0.11.2
CATEGORIES=	cad python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyrtl/}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://ucsbarchlab.github.io/PyRTL/
COMMENT=	Register-transfer-level hardware design and simulation
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling-[0-9]*:../../devel/py-hatchling
DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six

# as of 0.11.2
# 2 failed, 1176 passed, 9 skipped
# 'make test' fails with 2 arithmetic FAILs.
TEST_DEPENDS+=	${PYPKGPREFIX}-tox-[0-9]*:../../devel/py-tox
TEST_DEPENDS+=	${PYPKGPREFIX}-nose-[0-9]*:../../devel/py-nose

USE_LANGUAGES=	c # for test

# for tests
.include "../../lang/python/tool.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
