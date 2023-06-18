# $NetBSD: Makefile,v 1.1 2023/06/18 12:10:23 adam Exp $

DISTNAME=	zope.i18nmessageid-6.0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=z/zope.i18nmessageid/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/zopefoundation/zope.i18nmessageid
COMMENT=	Zope Message Identifiers for internationalization
LICENSE=	zpl-2.1

TEST_DEPENDS+=	${PYPKGPREFIX}-coverage-[0-9]*:../../devel/py-coverage
TEST_DEPENDS+=	${PYPKGPREFIX}-zope.testrunner-[0-9]*:../../devel/py-zope.testrunner

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
