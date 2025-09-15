# $NetBSD: Makefile,v 1.7 2025/09/15 11:53:29 adam Exp $

DISTNAME=	zope_i18nmessageid-8.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/./}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=z/zope.i18nmessageid/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/zopefoundation/zope.i18nmessageid
COMMENT=	Zope Message Identifiers for internationalization
LICENSE=	zpl-2.1

DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
TEST_DEPENDS+=	${PYPKGPREFIX}-coverage-[0-9]*:../../devel/py-coverage
TEST_DEPENDS+=	${PYPKGPREFIX}-zope.testrunner>=6.4:../../devel/py-zope.testrunner

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
