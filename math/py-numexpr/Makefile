# $NetBSD: Makefile,v 1.6 2016/07/15 07:18:45 wiz Exp $

DISTNAME=	numexpr-2.6.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_GITHUB:=pydata/}
GITHUB_TAG=	v${PKGVERSION_NOREV}
GITHUB_PROJECT=	numexpr

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pydata/numexpr
COMMENT=	Numerical expression evaluator for NumPy
LICENSE=	mit

USE_LANGUAGES=	c++
REPLACE_PYTHON=	numexpr/cpuinfo.py

do-test:
	${PYTHONBIN} -c "import numexpr; numexpr.test()"

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
