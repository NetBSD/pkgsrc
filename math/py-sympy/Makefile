# $NetBSD: Makefile,v 1.43 2025/04/28 20:52:47 adam Exp $

DISTNAME=	sympy-1.14.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/sympy/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://www.sympy.org/
COMMENT=	Python library for symbolic mathematics
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-mpmath>=1.1.0:../../math/py-mpmath

USE_LANGUAGES=	# none

REPLACE_PYTHON+=	sympy/utilities/tests/diagnose_imports.py

SUBST_CLASSES+=		manpath
SUBST_SED.manpath=	-e 's,share/man,${PKGMANDIR},'
SUBST_FILES.manpath+=	setup.py
SUBST_STAGE.manpath=	pre-configure
SUBST_MESSAGE.manpath=	Fix man page installation path.

post-install:
	cd ${DESTDIR}${PREFIX} && \
	${MV} bin/isympy bin/isympy-${PYVERSSUFFIX} && \
	${MV} ${PKGMANDIR}/man1/isympy.1 ${PKGMANDIR}/man1/isympy-${PYVERSSUFFIX}.1

.include "../../lang/python/application.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
