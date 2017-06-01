# $NetBSD: Makefile,v 1.2 2017/06/01 13:31:45 wiz Exp $

DISTNAME=	packaging-16.8
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/packaging/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.python.org/pypi/packaging
COMMENT=	Core utilities for Python packages
LICENSE=	modified-bsd OR apache-2.0

DEPENDS+=		${PYPKGPREFIX}-pyparsing-[0-9]*:../../devel/py-pyparsing
DEPENDS+=		${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six
# needed for tests, but would introduce dependency cycle
#BUILD_DEPENDS+=		${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test

#BOOTSTRAP_SETUPTOOLS=	yes

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
