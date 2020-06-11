# $NetBSD: Makefile,v 1.68 2020/06/11 08:02:35 adam Exp $

DISTNAME=	Cython-0.29.20
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=C/Cython/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://cython.org/
COMMENT=	C-Extensions for Python
LICENSE=	apache-1.1

REPLACE_PYTHON+=	Cython/Build/Cythonize.py
REPLACE_PYTHON+=	Cython/Debugger/Cygdb.py
REPLACE_PYTHON+=	Cython/Debugger/libpython.py
REPLACE_PYTHON+=	cython.py

# for test only
#USE_LANGUAGES=	c c++
do-test:
	cd ${WRKSRC} && ${PYTHONBIN} runtests.py

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} cython cython-${PYVERSSUFFIX} && \
	${MV} cythonize cythonize-${PYVERSSUFFIX} && \
	${MV} cygdb cygdb-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
# for test only
#.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
