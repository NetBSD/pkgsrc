# $NetBSD: Makefile,v 1.29 2023/11/02 11:04:14 adam Exp $

DISTNAME=	jupyter_core-5.5.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=j/jupyter_core/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://jupyter.org/
COMMENT=	Jupyter core package
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling>=1.4:../../devel/py-hatchling
DEPENDS+=	${PYPKGPREFIX}-platformdirs>=2.5:../../misc/py-platformdirs
DEPENDS+=	${PYPKGPREFIX}-traitlets>=5.3:../../devel/py-traitlets
TEST_DEPENDS+=	${PYPKGPREFIX}-ipykernel-[0-9]*:../../devel/py-ipykernel
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-test-timeout-[0-9]*:../../devel/py-test-timeout

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

REPLACE_PYTHON+=	jupyter_core/troubleshoot.py

SUBST_CLASSES+=			fix-prefix
SUBST_STAGE.fix-prefix=		pre-configure
SUBST_MESSAGE.fix-prefix=	Fixing prefix.
SUBST_FILES.fix-prefix=		jupyter_core/paths.py
SUBST_VARS.fix-prefix=		PREFIX

post-install:
	${RM} -f ${DESTDIR}${PREFIX}/${PYSITELIB}/jupyter_core/paths.py.orig
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} jupyter jupyter-${PYVERSSUFFIX} && \
	${MV} jupyter-migrate jupyter-migrate-${PYVERSSUFFIX} && \
	${MV} jupyter-troubleshoot jupyter-troubleshoot-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/application.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
