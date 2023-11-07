# $NetBSD: Makefile,v 1.12 2023/11/07 22:38:00 wiz Exp $

DISTNAME=	stevedore-4.1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/stevedore/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/dreamhost/stevedore
COMMENT=	Manage dynamic plugins for Python applications
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-pbr>=2.1.1:../../devel/py-pbr
TEST_DEPENDS+=	${PYPKGPREFIX}-sphinx-[0-9]*:../../textproc/py-sphinx
TEST_DEPENDS+=	${PYPKGPREFIX}-testtools-[0-9]*:../../devel/py-testtools

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27 38

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHONBIN} -m unittest discover -v

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
