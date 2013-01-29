# $NetBSD: Makefile,v 1.12 2013/01/29 06:06:54 wiz Exp $
#

DISTNAME=	Cython-0.17.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/Cy/cy/}
CATEGORIES=	lang python
MASTER_SITES=	http://cython.org/release/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://cython.org/
COMMENT=	C-Extensions for Python
LICENSE=	apache-1.1

USE_LANGUAGES=	c
PYDISTUTILSPKG= yes
PYTHON_VERSIONS_INCLUDE_3X=	yes

PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX}
PLIST_VARS=	cygdb

REPLACE_PYTHON+=	Cython/Debugger/Cygdb.py
REPLACE_PYTHON+=	Cython/Debugger/libpython.py
REPLACE_PYTHON+=	cython.py

post-extract:
	cd ${WRKSRC}/bin && ${MV} cython cython${PYVERSSUFFIX}
	cd ${WRKSRC}/bin && ${MV} cygdb cygdb${PYVERSSUFFIX}

# for test only
#USE_LANGUAGES+= c++
do-test:
	(cd ${WRKSRC} && ${PYTHONBIN} runtests.py)

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
# for test only
#.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
