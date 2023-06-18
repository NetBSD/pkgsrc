# $NetBSD: Makefile,v 1.43 2023/06/18 05:26:01 adam Exp $

DISTNAME=	zope.interface-6.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/zope.i/ZopeI/}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=z/zope.interface/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/zopefoundation/zope.interface
COMMENT=	The zope.interface package used in Zope 3 and Twisted
LICENSE=	zpl-2.1

TEST_DEPENDS+=	${PYPKGPREFIX}-coverage>=5.0.3:../../devel/py-coverage
TEST_DEPENDS+=	${PYPKGPREFIX}-zope.event-[0-9]*:../../devel/py-zope.event
TEST_DEPENDS+=	${PYPKGPREFIX}-zope.testing-[0-9]*:../../devel/py-zope.testing

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
