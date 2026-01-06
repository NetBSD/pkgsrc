# $NetBSD: Makefile,v 1.17 2026/01/06 11:18:42 wiz Exp $

DISTNAME=	doc8-2.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/doc8/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/pycqa/doc8
COMMENT=	Opinionated style checker for rst styles of documentation
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=7.0.0:../../devel/py-setuptools_scm
DEPENDS+=	${PYPKGPREFIX}-docutils>=0.21.2:../../textproc/py-docutils
DEPENDS+=	${PYPKGPREFIX}-pygments-[0-9]*:../../textproc/py-pygments
DEPENDS+=	${PYPKGPREFIX}-restructuredtext_lint>=0.7:../../devel/py-restructuredtext_lint
DEPENDS+=	${PYPKGPREFIX}-stevedore-[0-9]*:../../devel/py-stevedore

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	310 311 # py-sphinx via py-stevedore

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} doc8 doc8-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
