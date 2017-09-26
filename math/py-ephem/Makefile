# $NetBSD: Makefile,v 1.15 2017/09/26 17:32:26 adam Exp $

DISTNAME=	pyephem-3.7.6.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/pyephem/ephem/}
CATEGORIES=	math geography python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyephem/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.rhodesmill.org/brandon/projects/pyephem.html
COMMENT=	Scientific-grade astronomical computations for Python
LICENSE=	gnu-lgpl-v3 OR gnu-gpl-v3

REPLACE_PYTHON+=	ephem/tests/test_*.py

.include "../../lang/python/application.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
