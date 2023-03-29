# $NetBSD: Makefile,v 1.12 2023/03/29 09:34:06 wiz Exp $

DISTNAME=	curtsies-0.4.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/curtsies/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/bpython/curtsies
COMMENT=	Curses-like terminal wrapper, with colored strings
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-blessed>=1.5:../../devel/py-blessed
DEPENDS+=	${PYPKGPREFIX}-cwcwidth-[0-9]*:../../devel/py-cwcwidth
TEST_DEPENDS+=	${PYPKGPREFIX}-mock-[0-9]*:../../devel/py-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-nose-[0-9]*:../../devel/py-nose
TEST_DEPENDS+=	${PYPKGPREFIX}-pyte-[0-9]*:../../devel/py-pyte

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/pyversion.mk"

.if ${PYTHON_VERSION} < 308
DEPENDS+=	${PYPKGPREFIX}-backports.cached-property-[0-9]*:../../devel/py-backports.cached-property
.endif

do-test:
	cd ${WRKSRC}/tests && ${SETENV} ${TEST_ENV} ${PYTHONBIN} -m unittest discover -v

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
