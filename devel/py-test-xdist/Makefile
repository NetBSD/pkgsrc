# $NetBSD: Makefile,v 1.17 2018/11/11 21:57:17 adam Exp $

DISTNAME=	pytest-xdist-1.24.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pytest-xdist/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pytest-dev/pytest-xdist
COMMENT=	Plugin for distributed testing and loop-on-failing modes
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-execnet>=1.1:../../devel/py-execnet
DEPENDS+=	${PYPKGPREFIX}-py>=1.4.22:../../devel/py-py
DEPENDS+=	${PYPKGPREFIX}-test>=3.0.0:../../devel/py-test
DEPENDS+=	${PYPKGPREFIX}-test-forked-[0-9]*:../../devel/py-test-forked
BUILD_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm-[0-9]*:../../devel/py-setuptools_scm

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
