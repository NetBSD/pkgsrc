# $NetBSD: Makefile,v 1.17 2022/01/27 09:18:53 adam Exp $

DISTNAME=	jupyter_core-4.9.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=j/jupyter_core/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://jupyter.org/
COMMENT=	Jupyter core package
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-traitlets>=4.1.0:../../devel/py-traitlets
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

USE_PKG_RESOURCES=	yes

SUBST_CLASSES+=			fix-prefix
SUBST_STAGE.fix-prefix=		pre-configure
SUBST_MESSAGE.fix-prefix=	Fixing prefix.
SUBST_FILES.fix-prefix=		jupyter_core/paths.py
SUBST_VARS.fix-prefix=		PREFIX

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} jupyter jupyter-${PYVERSSUFFIX} && \
	${MV} jupyter-migrate jupyter-migrate-${PYVERSSUFFIX} && \
	${MV} jupyter-troubleshoot jupyter-troubleshoot-${PYVERSSUFFIX} || ${TRUE}

do-test:
	cd ${WRKSRC}/jupyter_core && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
