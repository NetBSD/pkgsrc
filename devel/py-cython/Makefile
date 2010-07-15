# $NetBSD: Makefile,v 1.1.1.1 2010/07/15 17:41:57 drochner Exp $
#

DISTNAME=	Cython-0.12.1
PKGNAME=	${PYPKGPREFIX}-cython-0.12.1
CATEGORIES=	lang python
MASTER_SITES=	http://cython.org/release/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://cython.org/
COMMENT=	C-Extensions for Python
LICENSE=	apache-1.1

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	c
PYDISTUTILSPKG= yes

PYTHON_VERSIONS_ACCEPTED= 26 25
PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX}

post-extract:
	cd ${WRKSRC}/bin && ${MV} cython cython${PYVERSSUFFIX}

# for test only
#USE_LANGUAGES+= c++
do-test:
	(cd ${WRKSRC} && ${PYTHONBIN} runtests.py)

.include "../../lang/python/extension.mk"
# for test only
#.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
