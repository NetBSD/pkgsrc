# $NetBSD: Makefile,v 1.37 2017/09/03 18:48:54 adam Exp $

DISTNAME=	Cython-0.26.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	lang python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/cython/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://cython.org/
COMMENT=	C-Extensions for Python
LICENSE=	apache-1.1

USE_LANGUAGES=	c

PLIST_VARS=	cygdb

REPLACE_PYTHON+=	Cython/Build/Cythonize.py
REPLACE_PYTHON+=	Cython/Debugger/Cygdb.py
REPLACE_PYTHON+=	Cython/Debugger/libpython.py
REPLACE_PYTHON+=	cython.py

# for test only
#USE_LANGUAGES+= c++
do-test:
	cd ${WRKSRC} && ${PYTHONBIN} runtests.py

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
		${MV} cython cython${PYVERSSUFFIX} && \
		${MV} cythonize cythonize${PYVERSSUFFIX} && \
		${MV} cygdb cygdb${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
# for test only
#.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
