# $NetBSD: Makefile,v 1.10 2020/08/31 23:07:00 wiz Exp $

DISTNAME=	zope.component-4.6.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/zope.c/ZopeC/}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=z/zope.component/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/zopefoundation/zope.component
COMMENT=	Zope Component Architecture modules
LICENSE=	zpl-2.1

DEPENDS+=	${PYPKGPREFIX}-zope.deferredimport>=4.2.1:../../devel/py-zope.deferredimport
DEPENDS+=	${PYPKGPREFIX}-zope.deprecation>=4.3.0:../../devel/py-zope.deprecation
DEPENDS+=	${PYPKGPREFIX}-ZopeEvent-[0-9]*:../../devel/py-ZopeEvent
DEPENDS+=	${PYPKGPREFIX}-zope.hookable>=4.2.0:../../devel/py-zope.hookable
DEPENDS+=	${PYPKGPREFIX}-ZopeInterface>=4.1.0:../../devel/py-ZopeInterface

PYTHON_VERSIONED_DEPENDENCIES+=	setuptools

.include "../../lang/python/egg.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
