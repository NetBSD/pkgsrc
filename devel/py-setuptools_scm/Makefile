# $NetBSD: Makefile,v 1.46 2025/08/20 19:16:11 wiz Exp $

DISTNAME=	setuptools_scm-9.2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/setuptools_scm/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pypa/setuptools_scm
COMMENT=	Manage your versions by scm tags
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-packaging>=20.0:../../devel/py-packaging
DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
TEST_DEPENDS+=	git-base-[0-9]*:../../devel/git-base
TEST_DEPENDS+=	${PYPKGPREFIX}-mercurial-[0-9]*:../../devel/py-mercurial
TEST_DEPENDS+=	${PYPKGPREFIX}-pip-[0-9]*:../../devel/py-pip
TEST_DEPENDS+=	${PYPKGPREFIX}-virtualenv>=20:../../devel/py-virtualenv
TEST_DEPENDS+=	${PYPKGPREFIX}-test-timeout>=0:../../devel/py-test-timeout

USE_LANGUAGES=	# none

.include "../../lang/python/pyversion.mk"
.if ${PYTHON_VERSION} < 310
DEPENDS+=	${PYPKGPREFIX}-importlib-metadata>=4.6:../../devel/py-importlib-metadata
DEPENDS+=	${PYPKGPREFIX}-typing-extensions-[0-9]*:../../devel/py-typing-extensions
.endif
.if ${PYTHON_VERSION} < 311
DEPENDS+=	${PYPKGPREFIX}-tomli>=1.0.0:../../textproc/py-tomli
.endif

# test status as of 9.2.0
# 2 failed, 386 passed, 15 skipped, 1 xfailed

post-install:
	cd ${DESTDIR}${PREFIX}/bin && ${MV} setuptools-scm setuptools-scm-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
