# $NetBSD: Makefile,v 1.5 2022/01/04 20:53:01 wiz Exp $

DISTNAME=	doc8-0.10.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/doc8/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/pycqa/doc8
COMMENT=	Opinionated style checker for rst styles of documentation
LICENSE=	apache-2.0

BUILD_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm-[0-9]*:../../devel/py-setuptools_scm
DEPENDS+=	${PYPKGPREFIX}-docutils-[0-9]*:../../textproc/py-docutils
DEPENDS+=	${PYPKGPREFIX}-pygments-[0-9]*:../../textproc/py-pygments
DEPENDS+=	${PYPKGPREFIX}-restructuredtext_lint>=0.7:../../devel/py-restructuredtext_lint
DEPENDS+=	${PYPKGPREFIX}-stevedore-[0-9]*:../../devel/py-stevedore

USE_LANGUAGES=	# none

PYSETUP=	-c 'from setuptools import setup; setup()'

PYTHON_VERSIONS_INCOMPATIBLE=	27

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} doc8 doc8-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
