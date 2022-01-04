# $NetBSD: Makefile,v 1.38 2022/01/04 20:52:47 wiz Exp $

DISTNAME=	zope.interface-5.4.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/zope.i/ZopeI/}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=z/zope.interface/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/zopefoundation/zope.interface
COMMENT=	The zope.interface package used in Zope 3 and Twisted
LICENSE=	zpl-2.1

TEST_DEPENDS+=	${PYPKGPREFIX}-ZopeEvent-[0-9]*:../../devel/py-ZopeEvent
TEST_DEPENDS+=	${PYPKGPREFIX}-zope.testing-[0-9]*:../../devel/py-zope.testing

PYTHON_VERSIONED_DEPENDENCIES+=	setuptools

.include "../../lang/python/egg.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
