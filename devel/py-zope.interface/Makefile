# $NetBSD: Makefile,v 1.11 2024/11/11 07:28:31 wiz Exp $

DISTNAME=	zope.interface-7.1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=z/zope.interface/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/zopefoundation/zope.interface
COMMENT=	Zope interfaces for Python
LICENSE=	zpl-2.1

WHEEL_NAME=	${DISTNAME:S/_/./}

DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TEST_DEPENDS+=	${PYPKGPREFIX}-coverage>=5.0.3:../../devel/py-coverage
TEST_DEPENDS+=	${PYPKGPREFIX}-zope.event-[0-9]*:../../devel/py-zope.event
TEST_DEPENDS+=	${PYPKGPREFIX}-zope.testing-[0-9]*:../../devel/py-zope.testing

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
