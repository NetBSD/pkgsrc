# $NetBSD: Makefile,v 1.12 2024/03/05 16:55:53 adam Exp $

DISTNAME=	ipyparallel-8.7.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	parallel python
MASTER_SITES=	${MASTER_SITE_PYPI:=i/ipyparallel/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ipython.org/
COMMENT=	Interactive Parallel Computing with IPython
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling>=0.25:../../devel/py-hatchling
#TOOL_DEPENDS+=	${PYPKGPREFIX}-jupyterlab>=4:../../www/py-jupyterlab
DEPENDS+=	${PYPKGPREFIX}-decorator-[0-9]*:../../devel/py-decorator
DEPENDS+=	${PYPKGPREFIX}-entrypoints-[0-9]*:../../devel/py-entrypoints
DEPENDS+=	${PYPKGPREFIX}-dateutil>=2.1:../../time/py-dateutil
DEPENDS+=	${PYPKGPREFIX}-ipykernel>=4.4:../../devel/py-ipykernel
DEPENDS+=	${PYPKGPREFIX}-ipython>=4.0:../../devel/py-ipython
DEPENDS+=	${PYPKGPREFIX}-jupyter_client-[0-9]*:../../devel/py-jupyter_client
DEPENDS+=	${PYPKGPREFIX}-psutil-[0-9]*:../../sysutils/py-psutil
DEPENDS+=	${PYPKGPREFIX}-tornado>=5.1:../../www/py-tornado
DEPENDS+=	${PYPKGPREFIX}-tqdm-[0-9]*:../../misc/py-tqdm
DEPENDS+=	${PYPKGPREFIX}-traitlets>=4.3:../../devel/py-traitlets
DEPENDS+=	${PYPKGPREFIX}-zmq>=18.0.0:../../net/py-zmq
TEST_DEPENDS+=	${PYPKGPREFIX}-test-asyncio-[0-9]*:../../devel/py-test-asyncio
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov
#TEST_DEPENDS+=	${PYPKGPREFIX}-test-tornado-[0-9]*:../../devel/py-test-tornado
TEST_DEPENDS+=	${PYPKGPREFIX}-testpath-[0-9]*:../../devel/py-testpath

USE_LANGUAGES=	# none

PYTHON_SELF_CONFLICT=	yes

REPLACE_PYTHON+=	ipyparallel/apps/iploggerapp.py
REPLACE_PYTHON+=	ipyparallel/cluster/app.py
REPLACE_PYTHON+=	ipyparallel/controller/app.py
REPLACE_PYTHON+=	ipyparallel/controller/heartmonitor.py
REPLACE_PYTHON+=	ipyparallel/engine/app.py

PYTHON_VERSIONS_INCOMPATIBLE=	27 38

post-install:
.for bin in ipcluster ipcontroller ipengine
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} ${bin} ${bin}-${PYVERSSUFFIX} || ${TRUE}
.endfor

.include "../../lang/python/application.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
