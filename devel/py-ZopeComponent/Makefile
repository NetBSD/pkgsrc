# $NetBSD: Makefile,v 1.4 2016/11/11 09:45:13 fhajny Exp $

DISTNAME=	zope.component-4.3.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/zope.c/ZopeC/}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=z/zope.component/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://docs.zope.org/zopetoolkit/
COMMENT=	Zope Component Architecture modules
LICENSE=	zpl-2.1

DEPENDS+=	${PYPKGPREFIX}-ZopeEvent-[0-9]*:../../devel/py-ZopeEvent
DEPENDS+=	${PYPKGPREFIX}-ZopeInterface>=4.1.0:../../devel/py-ZopeInterface

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
