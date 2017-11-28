# $NetBSD: Makefile,v 1.43 2017/11/28 09:07:23 adam Exp $

DISTNAME=	rpy2-2.9.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/rpy2/rpy/}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=r/rpy2/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://rpy.sourceforge.net/
COMMENT=	R interface for Python
LICENSE=	mpl-1.1 OR gnu-gpl-v2 OR gnu-lgpl-v2.1

DEPENDS+=	${PYPKGPREFIX}-jinja2-[0-9]*:../../textproc/py-jinja2
DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-sqlite3-[0-9]*:../../databases/py-sqlite3

USE_LANGUAGES+=		c fortran77

BUILDLINK_API_DEPENDS.R+=	R>=3.3.0

LDFLAGS.SunOS+=		-mimpure-text

REPLACE_PYTHON=		rpy/tests.py

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../devel/pcre/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../math/R/buildlink3.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/readline.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
