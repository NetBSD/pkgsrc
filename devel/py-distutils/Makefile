# $NetBSD: Makefile,v 1.3 2004/07/22 09:16:01 recht Exp $
#

DISTNAME=	Distutils-1.0.2
PKGNAME=	${PYPKGPREFIX}-distutils-1.0.2
CATEGORIES=	devel python
MASTER_SITES=	http://www.python.org/sigs/distutils-sig/download/

MAINTAINER=	drochner@NetBSD.org
HOMEPAGE=	http://www.python.org/sigs/distutils-sig/
COMMENT=	Distribution Utilities for Python

PYTHON_VERSIONS_ACCEPTED= 15
PYSITELIB=	lib/python1.5/site-packages
PLIST_SUBST+=	PYSITELIB=${PYSITELIB}
PYTHON_DISTUTILS_BOOTSTRAP=	yes

do-build:
	(cd ${WRKSRC} && ${PYTHONBIN} setup.py build)

do-install:
	(cd ${WRKSRC} && ${PYTHONBIN} setup.py install)

.include "../../lang/python/pyversion.mk"
.include "../../mk/bsd.pkg.mk"
