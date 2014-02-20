# $NetBSD: Makefile,v 1.20 2014/02/20 09:29:03 wiz Exp $

DISTNAME=	Cython-0.20.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/Cy/cy/}
CATEGORIES=	lang python
MASTER_SITES=	http://cython.org/release/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://cython.org/
COMMENT=	C-Extensions for Python
LICENSE=	apache-1.1

USE_LANGUAGES=	c

PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX}
PLIST_VARS=	cygdb

REPLACE_PYTHON+=	Cython/Build/Cythonize.py
REPLACE_PYTHON+=	Cython/Debugger/Cygdb.py
REPLACE_PYTHON+=	Cython/Debugger/libpython.py
REPLACE_PYTHON+=	cython.py

# for test only
#USE_LANGUAGES+= c++
do-test:
	(cd ${WRKSRC} && ${PYTHONBIN} runtests.py)

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
		${MV} cython cython${PYVERSSUFFIX} && \
		${MV} cygdb cygdb${PYVERSSUFFIX}

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
# for test only
#.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
