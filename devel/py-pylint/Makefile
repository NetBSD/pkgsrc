# $NetBSD: Makefile,v 1.44 2021/02/22 09:24:34 adam Exp $

DISTNAME=	pylint-2.7.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pylint/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.pylint.org/
COMMENT=	Python source code analyzer
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-astroid>=2.5.0:../../devel/py-astroid
DEPENDS+=	${PYPKGPREFIX}-isort>=4.2.5:../../devel/py-isort
DEPENDS+=	${PYPKGPREFIX}-mccabe>=0.6:../../devel/py-mccabe
DEPENDS+=	${PYPKGPREFIX}-toml>=0.7.1:../../textproc/py-toml
BUILD_DEPENDS+=	${PYPKGPREFIX}-test-runner-[0-9]*:../../devel/py-test-runner
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

INSTALLATION_DIRS=	${PKGMANDIR}/man1

post-install:
.for file in epylint pylint pyreverse symilar
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} ${file} ${file}-${PYVERSSUFFIX} || ${TRUE}
	${INSTALL_DATA} ${WRKSRC}/man/${file}.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/${file}-${PYVERSSUFFIX}.1
.endfor

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} PYTHONPATH=. pytest-${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
