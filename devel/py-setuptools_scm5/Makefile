# $NetBSD: Makefile,v 1.3 2024/04/30 11:17:53 wiz Exp $

DISTNAME=	setuptools_scm-5.0.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/setuptools_scm/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pypa/setuptools_scm
COMMENT=	Manage your versions by scm tags (python 2.7 version)
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-toml-[0-9]*:../../textproc/py-toml
# does not support python 2.7
#TEST_DEPENDS+=	${PYPKGPREFIX}-mercurial-[0-9]*:../../devel/py-mercurial
TEST_DEPENDS+=	${PYPKGPREFIX}-pip-[0-9]*:../../devel/py-pip20
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test4

PYTHON_VERSIONS_ACCEPTED=	27

USE_LANGUAGES=	# none

do-test:
	cd ${WRKSRC} && pytest-${PYVERSSUFFIX} testing

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
