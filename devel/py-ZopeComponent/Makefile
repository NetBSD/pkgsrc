# $NetBSD: Makefile,v 1.7 2018/10/28 15:21:23 taca Exp $

DISTNAME=	zope.component-4.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/zope.c/ZopeC/}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=z/zope.component/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://docs.zope.org/zopetoolkit/
COMMENT=	Zope Component Architecture modules
LICENSE=	zpl-2.1

DEPENDS+=	${PYPKGPREFIX}-zope.deferredimport>=4.2.1:../../devel/py-zope.deferredimport
DEPENDS+=	${PYPKGPREFIX}-zope.deprecation>=4.3.0:../../devel/py-zope.deprecation
DEPENDS+=	${PYPKGPREFIX}-ZopeEvent-[0-9]*:../../devel/py-ZopeEvent
DEPENDS+=	${PYPKGPREFIX}-zope.hookable>=4.2.0:../../devel/py-zope.hookable
DEPENDS+=	${PYPKGPREFIX}-ZopeInterface>=4.1.0:../../devel/py-ZopeInterface

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
