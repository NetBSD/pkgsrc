# $NetBSD: Makefile,v 1.50 2021/12/30 13:05:38 adam Exp $

DISTNAME=	rpy2-3.4.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/rpy2/rpy/}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=r/rpy2/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://rpy2.github.io/
COMMENT=	R interface for Python
LICENSE=	mpl-1.1 OR gnu-gpl-v2 OR gnu-lgpl-v2.1

DEPENDS+=	${PYPKGPREFIX}-jinja2-[0-9]*:../../textproc/py-jinja2
DEPENDS+=	${PYPKGPREFIX}-tzlocal-[0-9]*:../../time/py-tzlocal
DEPENDS+=	${PYPKGPREFIX}-pytz-[0-9]*:../../time/py-pytz
DEPENDS+=	${PYPKGPREFIX}-cffi-[0-9]*:../../devel/py-cffi
DEPENDS+=	${PYPKGPREFIX}-sqlite3-[0-9]*:../../databases/py-sqlite3
DEPENDS+=	R-dbplyr-[0-9]*:../../databases/R-dbplyr
DEPENDS+=	R-ggplot2-[0-9]*:../../graphics/R-ggplot2
DEPENDS+=	R-lazyeval-[0-9]*:../../devel/R-lazyeval
DEPENDS+=	R-rlang-[0-9]*:../../devel/R-rlang
DEPENDS+=	R-tidyr-[0-9]*:../../math/R-tidyr
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-ipython-[0-9]*:../../devel/py-ipython
TEST_DEPENDS+=	${PYPKGPREFIX}-pandas-[0-9]*:../../math/py-pandas

USE_LANGUAGES+=		c fortran77

BUILDLINK_API_DEPENDS.R+=	R>=3.3.0

LDFLAGS.SunOS+=		-mimpure-text

REPLACE_PYTHON=		rpy/tests.py

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../devel/pcre2/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../math/R/buildlink3.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/readline.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
