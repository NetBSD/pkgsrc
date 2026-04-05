# $NetBSD: Makefile,v 1.50 2026/04/05 08:35:51 fox Exp $

DISTNAME=	glances-4.5.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/g/G/}
CATEGORIES=	sysutils python
MASTER_SITES=	${MASTER_SITE_PYPI:=g/glances/}

MAINTAINER=	fox@NetBSD.org
HOMEPAGE=	https://nicolargo.github.io/glances/
COMMENT=	Cross-platform curses-based monitoring tool
LICENSE=	gnu-lgpl-v3

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-defusedxml-[0-9]*:../../textproc/py-defusedxml
DEPENDS+=	${PYPKGPREFIX}-packaging-[0-9]*:../../devel/py-packaging
DEPENDS+=	${PYPKGPREFIX}-psutil>=5.6.7:../../sysutils/py-psutil
DEPENDS+=	${PYPKGPREFIX}-jinja2>=3.1.6:../../textproc/py-jinja2
# optional
DEPENDS+=	${PYPKGPREFIX}-orjson>=0:../../textproc/py-orjson
TEST_DEPENDS+=	${PYPKGPREFIX}-requests-[0-9]*:../../devel/py-requests
TEST_DEPENDS+=	${PYPKGPREFIX}-selenium-[0-9]*:../../www/py-selenium
# DEPENDS for WebUI/RestFull API
#TEST_DEPENDS+=	${PYPKGPREFIX}-fastapi-[0-9]*:../../wip/py-fastapi
#TEST_DEPENDS+=	${PYPKGPREFIX}-uvicorn-[0-9]*:../../www/py-uvicorn

# for testing
ALLOW_NETWORK_ACCESS=	yes
# as of 4.3.0.8
# 35 failed, 35 passed, 2 skipped, 5 errors

USE_LANGUAGES=	# none

SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	pre-configure
SUBST_MESSAGE.prefix=	Set correct prefix in setup.py
SUBST_FILES.prefix=	pyproject.toml
SUBST_SED.prefix=	-e 's,share/man,${PKGMANDIR},'

post-extract:
	# Removes the nodejs component which is not required.
	${RM} -fR ${WRKSRC}/glances/outputs/static

post-install:
	# remove file in pycache
	${RM} -rf ${DESTDIR}${PREFIX}/${PYSITELIB}/glances/plugins/__pycache__/__init__.py
	${RM} -rf ${DESTDIR}${PREFIX}/${PYSITELIB}/glances/plugins/__pycache__/__pycache__/__init__.cpython-313.opt-1.pyc
	${RM} -rf ${DESTDIR}${PREFIX}/${PYSITELIB}/glances/plugins/__pycache__/__pycache__/__init__.cpython-313.pyc
	cd ${DESTDIR}${PREFIX} && \
	${MV} bin/glances bin/glances-${PYVERSSUFFIX} && \
	${MV} ${PKGMANDIR}/man1/glances.1 ${PKGMANDIR}/man1/glances-${PYVERSSUFFIX}.1 && \
	${MV} share/doc/glances share/doc/glances-${PYVERSSUFFIX}

.include "../../lang/python/batteries-included.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
