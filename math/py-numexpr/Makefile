# $NetBSD: Makefile,v 1.4 2014/01/21 13:26:52 wiz Exp $

DISTNAME=	numexpr-2.2.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math
MASTER_SITES=	http://numexpr.googlecode.com/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://code.google.com/p/numexpr/
COMMENT=	Numerical expression evaluator for NumPy
LICENSE=	mit

USE_LANGUAGES=	c++
REPLACE_PYTHON=	numexpr/cpuinfo.py

do-test:
	${PYTHONBIN} -c "import numexpr; numexpr.test()"

.include "../../lang/python/application.mk"
.include "../../lang/python/distutils.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
