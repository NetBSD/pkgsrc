# $NetBSD: Makefile,v 1.22 2026/11/07 07:48:48 wiz Exp $

DISTNAME=	guppy3-3.2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=g/guppy3/}

MAINTAINER=	gutteridge@NetBSD.org
HOMEPAGE=	https://github.com/zhuyifei1999/guppy3
COMMENT=	Python programming environment and heap analysis toolset
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-Tk-[0-9]*:../../x11/py-Tk

# Follow upstream (see .github/workflows/workflow.yml)
do-test:
	cd ${WRKSRC} && \
		${SETENV} ${TEST_ENV} ${PYTHONBIN} setup.py build_ext --inplace
	cd ${WRKSRC} && \
		${SETENV} ${TEST_ENV} ${PYTHONBIN} -c \
		'import guppy; guppy.hpy().test()'

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
