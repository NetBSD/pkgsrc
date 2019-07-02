# $NetBSD: Makefile,v 1.6 2019/07/02 10:01:09 adam Exp $

DISTNAME=	pathlib2-2.3.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pathlib2/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/mcmtroffaes/pathlib2
COMMENT=	Object-oriented filesystem paths
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six

.include "../../lang/python/pyversion.mk"
.if ${_PYTHON_VERSION} == 27
DEPENDS+=	${PYPKGPREFIX}-scandir-[0-9]*:../../devel/py-scandir
.endif

USE_LANGUAGES=	# none

do-test:
	cd ${WRKSRC} && ${PYTHONBIN} tests/test_pathlib2.py

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
