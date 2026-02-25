# $NetBSD: Makefile,v 1.23 2026/02/25 10:26:17 adam Exp $

DISTNAME=	bandit-1.9.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_PYPI:=b/bandit/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/PyCQA/bandit
COMMENT=	Security oriented static analyser for Python code
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-pbr>=2.0.0:../../devel/py-pbr
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-rich-[0-9]*:../../comms/py-rich
DEPENDS+=	${PYPKGPREFIX}-stevedore>=1.20.0:../../devel/py-stevedore
DEPENDS+=	${PYPKGPREFIX}-yaml>=5.3.1:../../textproc/py-yaml
# baseline
DEPENDS+=	${PYPKGPREFIX}-gitpython>=3.1.30:../../devel/py-gitpython
TEST_DEPENDS+=	${PYPKGPREFIX}-beautifulsoup4>=4.8.0:../../www/py-beautifulsoup4
TEST_DEPENDS+=	${PYPKGPREFIX}-fixtures>=3.0.0:../../devel/py-fixtures
TEST_DEPENDS+=	${PYPKGPREFIX}-testscenarios>=0.5.0:../../devel/py-testscenarios
TEST_DEPENDS+=	${PYPKGPREFIX}-testtools>=2.3.0:../../devel/py-testtools

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	310 311 # py-sphinx via py-pbr

.include "../../lang/python/pyversion.mk"
.if ${PYTHON_VERSION} < 311
TEST_DEPENDS+=	${PYPKGPREFIX}-tomli>=1.1.0:../../textproc/py-tomli
.endif

SUBST_CLASSES+=		mandir
SUBST_STAGE.mandir=	pre-configure
SUBST_MESSAGE.mandir=	Setting correct mandir.
SUBST_FILES.mandir=	setup.py
SUBST_SED.mandir=	-e 's,share/man,${PKGMANDIR},g'

post-install:
.for bin in bandit bandit-baseline bandit-config-generator
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} ${bin} ${bin}-${PYVERSSUFFIX} || ${TRUE}
.endfor
	cd ${DESTDIR}${PREFIX}/${PKGMANDIR} && \
	${MV} man1/bandit.1 man1/bandit-${PYVERSSUFFIX}.1 || ${TRUE}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
