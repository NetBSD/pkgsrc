# $NetBSD: Makefile,v 1.1 2014/06/14 16:46:52 rodent Exp $

DISTNAME=	pbr-0.8.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	https://pypi.python.org/packages/source/p/pbr/

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	http://pypi.python.org/pypi/pbr
COMMENT=	Python Build Reasonableness
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-pip-[0-9]*:../../devel/py-pip

REPLACE_PYTHON+=	pbr/tests/testpackage/setup.py

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
