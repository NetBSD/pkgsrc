# $NetBSD: Makefile,v 1.10 2014/05/09 07:37:10 wiz Exp $

DISTNAME=	pyephem-3.7.5.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/pyephem/ephem/}
CATEGORIES=	geography math
MASTER_SITES=	http://pypi.python.org/packages/source/p/pyephem/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.rhodesmill.org/brandon/projects/pyephem.html
COMMENT=	Scientific-grade astronomical computations for Python
LICENSE=	gnu-lgpl-v3 OR gnu-gpl-v3

do-test:
	(cd ${WRKSRC}/${PYSETUPSUBDIR} && ${SETENV} ${TEST_ENV} ${MAKE_ENV} \
	 ${PYTHONBIN} ${PYSETUP} ${PYSETUPARGS} "test")

PYTHON_VERSIONS_INCOMPATIBLE=	33 34

REPLACE_PYTHON+=	src/ephem/tests/test_angles.py
REPLACE_PYTHON+=	src/ephem/tests/test_bodies.py
REPLACE_PYTHON+=	src/ephem/tests/test_cities.py
REPLACE_PYTHON+=	src/ephem/tests/test_constants.py
REPLACE_PYTHON+=	src/ephem/tests/test_dates.py
REPLACE_PYTHON+=	src/ephem/tests/test_jpl.py
REPLACE_PYTHON+=	src/ephem/tests/test_launchpad_236872.py
REPLACE_PYTHON+=	src/ephem/tests/test_launchpad_244811.py
REPLACE_PYTHON+=	src/ephem/tests/test_observers.py
REPLACE_PYTHON+=	src/ephem/tests/test_rst.py
REPLACE_PYTHON+=	src/ephem/tests/test_stars.py
REPLACE_PYTHON+=	src/ephem/tests/test_usno.py
REPLACE_PYTHON+=	src/ephem/tests/test_usno_equinoxes.py

.include "../../lang/python/application.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
