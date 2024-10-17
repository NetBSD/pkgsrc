# $NetBSD: Makefile,v 1.11 2024/10/17 09:28:08 wiz Exp $

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

USE_LANGUAGES=	c # for test

# for tests
.include "../../lang/python/tool.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
