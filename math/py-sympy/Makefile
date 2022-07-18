# $NetBSD: Makefile,v 1.33 2022/07/18 12:49:20 jperkin Exp $

DISTNAME=	sympy-1.9
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/sympy/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://www.sympy.org/
COMMENT=	Python library for symbolic mathematics
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-mpmath>=0.19:../../math/py-mpmath

USE_LANGUAGES=	# none

REPLACE_PYTHON+=	sympy/utilities/tests/diagnose_imports.py

PYTHON_VERSIONS_INCOMPATIBLE=	27

USE_PKG_RESOURCES=	yes

SUBST_CLASSES+=		manpath
SUBST_SED.manpath=	-e 's,share/man,${PKGMANDIR},'
SUBST_FILES.manpath+=	setup.py
SUBST_STAGE.manpath=	pre-configure
SUBST_MESSAGE.manpath=	Fix man page installation path.

# advanced.pidigits is broken, don't worry if it fails
do-test:
	cd ${WRKSRC}/examples && ${PYTHONBIN} all.py

post-install:
	cd ${DESTDIR}${PREFIX} && \
	${MV} bin/isympy bin/isympy-${PYVERSSUFFIX} && \
	${MV} ${PKGMANDIR}/man1/isympy.1 ${PKGMANDIR}/man1/isympy-${PYVERSSUFFIX}.1

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
