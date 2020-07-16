# $NetBSD: Makefile,v 1.6 2020/07/16 06:08:13 adam Exp $

DISTNAME=	curtsies-0.3.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/curtsies/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/bpython/curtsies
COMMENT=	Curses-like terminal wrapper, with colored strings
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-blessings>=1.5:../../devel/py-blessings
DEPENDS+=	${PYPKGPREFIX}-wcwidth>=0.1.4:../../devel/py-wcwidth
.include "../../lang/python/pyversion.mk"
.if ${_PYTHON_VERSION} == 27
DEPENDS+=	${PYPKGPREFIX}-typing-[0-9]*:../../devel/py-typing
.endif
TEST_DEPENDS+=	${PYPKGPREFIX}-mock-[0-9]*:../../devel/py-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-nose-[0-9]*:../../devel/py-nose
TEST_DEPENDS+=	${PYPKGPREFIX}-pyte-[0-9]*:../../devel/py-pyte

USE_LANGUAGES=	# none

do-test:
	cd ${WRKSRC}/tests && ${PYTHONBIN} -m unittest discover -v

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
