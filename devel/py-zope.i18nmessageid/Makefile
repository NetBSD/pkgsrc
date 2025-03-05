# $NetBSD: Makefile,v 1.5 2025/03/05 09:57:30 wiz Exp $

DISTNAME=	zope_i18nmessageid-7.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/./}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=z/zope.i18nmessageid/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/zopefoundation/zope.i18nmessageid
COMMENT=	Zope Message Identifiers for internationalization
LICENSE=	zpl-2.1

DEPENDS+=	${PYPKGPREFIX}-setuptools>=75.8.2:../../devel/py-setuptools
TEST_DEPENDS+=	${PYPKGPREFIX}-coverage-[0-9]*:../../devel/py-coverage
TEST_DEPENDS+=	${PYPKGPREFIX}-zope.testrunner-[0-9]*:../../devel/py-zope.testrunner

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
