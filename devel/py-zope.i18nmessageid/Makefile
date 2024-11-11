# $NetBSD: Makefile,v 1.4 2024/11/11 07:28:31 wiz Exp $

DISTNAME=	zope_i18nmessageid-7.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/./}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=z/zope.i18nmessageid/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/zopefoundation/zope.i18nmessageid
COMMENT=	Zope Message Identifiers for internationalization
LICENSE=	zpl-2.1

WHEEL_NAME=	${DISTNAME:S/_/./}

DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TEST_DEPENDS+=	${PYPKGPREFIX}-coverage-[0-9]*:../../devel/py-coverage
TEST_DEPENDS+=	${PYPKGPREFIX}-zope.testrunner-[0-9]*:../../devel/py-zope.testrunner

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
