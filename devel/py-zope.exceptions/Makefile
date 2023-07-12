# $NetBSD: Makefile,v 1.9 2023/07/12 16:29:13 adam Exp $

DISTNAME=	zope.exceptions-5.0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=z/zope.exceptions/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/zopefoundation/zope.exceptions
COMMENT=	Zope testing helpers
LICENSE=	zpl-2.1

DEPENDS+=	${PYPKGPREFIX}-zope.interface-[0-9]*:../../devel/py-zope.interface
# circular dependency
#TEST_DEPENDS+=	${PYPKGPREFIX}-zope.testrunner-[0-9]*:../../devel/py-zope.testrunner

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
